<#
.SYNOPSIS
    Compiles every "practical N.cpp", runs it (feeding sample input from inputs\),
    and renders the console session as a terminal-style PNG in outputs\.

.EXAMPLE
    .\generate_outputs.ps1                      # all practicals
    .\generate_outputs.ps1 -Only "practical 7"  # only files whose name starts with this
#>
param(
    [string[]]$Only,
    [int]$Scale = 2            # 2 = crisp, high-DPI images
)

$ErrorActionPreference = 'Stop'
Add-Type -AssemblyName System.Drawing

$root     = $PSScriptRoot
$inDir    = Join-Path $root 'inputs'
$outDir   = Join-Path $root 'outputs'
$buildDir = Join-Path $outDir '.build'
New-Item -ItemType Directory -Force $outDir, $buildDir | Out-Null

# ---------------------------------------------------------------- theme ---
# Windows Terminal, dark theme, "Campbell" colour scheme, PowerShell profile.
$Theme = @{
    Body = '#0C0C0C'; TabRow = '#202020'; Border = '#454545'; Chrome = '#CCCCCC'
    out    = '#CCCCCC'   # program output
    in     = '#CCCCCC'   # text typed by the user (same colour, like a real terminal)
    prompt = '#CCCCCC'   # "PS C:\...>"
    op     = '#767676'   # PSReadLine operator colour (DarkGray)  -> &
    str    = '#3A96DD'   # PSReadLine string colour   (DarkCyan)  -> ".\file.exe"
    err    = '#E74856'
}
$FontName = 'Cascadia Mono'; $FontPx = 14; $LineH = 20; $Pad = 10; $TabRowH = 40; $MinW = 900
$IconFont = if ((New-Object System.Drawing.Text.InstalledFontCollection).Families.Name -contains 'Segoe Fluent Icons') { 'Segoe Fluent Icons' } else { 'Segoe MDL2 Assets' }
$PromptPath = $root

# ------------------------------------------------------------- compiler ---
function Get-Compiler {
    $gpp = Get-Command g++ -ErrorAction SilentlyContinue
    if ($gpp) { return @{ Kind = 'gcc'; Path = $gpp.Source } }
    $found = Get-ChildItem "$env:LOCALAPPDATA\Microsoft\WinGet\Packages\*WinLibs*\mingw64\bin\g++.exe", 'C:\mingw64\bin\g++.exe', 'C:\msys64\ucrt64\bin\g++.exe' -ErrorAction SilentlyContinue | Select-Object -First 1
    if ($found) { return @{ Kind = 'gcc'; Path = $found.FullName } }

    $vswhere = Join-Path ${env:ProgramFiles(x86)} 'Microsoft Visual Studio\Installer\vswhere.exe'
    if (Test-Path $vswhere) {
        $inst = & $vswhere -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath
        if ($inst) {
            $bat = Join-Path $inst 'VC\Auxiliary\Build\vcvars64.bat'
            if (Test-Path $bat) { return @{ Kind = 'msvc'; Path = $bat } }
        }
    }
    throw "No C++ compiler found. Install MSVC Build Tools (C++ workload) or MinGW g++."
}

function Build-All($sources, $compiler) {
    foreach ($s in $sources) { Remove-Item (Join-Path $buildDir "$($s.ExeName)") -ErrorAction SilentlyContinue }

    if ($compiler.Kind -eq 'gcc') {
        $ErrorActionPreference = 'Continue'   # g++ warnings on stderr must not abort the script
        $gpp = $compiler.Path; $extra = @()
        $mingw = Split-Path (Split-Path $gpp)
        if ($mingw -match ' ') {
            # MinGW's linker breaks when its own install path contains a space.
            # Use a space-free junction and point gcc's file search (-B) at it.
            $link = 'C:\Users\Public\mingw64'
            if (-not (Test-Path $link)) { cmd /c mklink /J "$link" "$mingw" | Out-Null }
            $gpp = Join-Path $link 'bin\g++.exe'
            $extra = @('-B', 'C:/Users/Public/mingw64/x86_64-w64-mingw32/lib/')
        }
        foreach ($s in $sources) {
            $log = Join-Path $buildDir "$($s.Safe).log"
            & $gpp @extra -std=c++17 -static $s.File.FullName -o (Join-Path $buildDir $s.ExeName) 2>&1 |
                ForEach-Object { "$_" } | Set-Content $log
        }
    }
    else {
        # One batch file so vcvars64.bat (slow) runs only once.
        $lines = @('@echo off', "call `"$($compiler.Path)`" >nul", "cd /d `"$buildDir`"")
        foreach ($s in $sources) {
            $lines += "cl /nologo /EHsc /std:c++17 /utf-8 `"$($s.File.FullName)`" /Fe`"$($s.ExeName)`" > `"$($s.Safe).log`" 2>&1"
        }
        $bat = Join-Path $buildDir '_build.bat'
        Set-Content -Path $bat -Value $lines -Encoding ASCII
        & cmd.exe /c "`"$bat`"" | Out-Null
    }
}

# ------------------------------------------------------- run & capture ---
function New-Seg($text, $kind) { [pscustomobject]@{ Text = $text; Kind = $kind } }

function Invoke-Session([string]$exe, [string[]]$inputs) {
    $psi = New-Object System.Diagnostics.ProcessStartInfo
    $psi.FileName = $exe
    $psi.WorkingDirectory = $root
    $psi.UseShellExecute = $false
    $psi.CreateNoWindow = $true
    $psi.RedirectStandardInput = $true
    $psi.RedirectStandardOutput = $true
    $psi.StandardOutputEncoding = [Text.Encoding]::UTF8

    $p = [Diagnostics.Process]::Start($psi)
    $segs = New-Object System.Collections.Generic.List[object]
    $buf = New-Object char[] 4096
    $task = $p.StandardOutput.ReadAsync($buf, 0, $buf.Length)
    $idx = 0; $stdinClosed = $false
    $last = [DateTime]::Now; $deadline = $last.AddSeconds(30)

    while ($true) {
        if ($task.Wait(50)) {
            $n = $task.Result
            if ($n -eq 0) { break }                                  # program finished
            $segs.Add((New-Seg ([string]::new($buf, 0, $n)) 'out'))
            $last = [DateTime]::Now
            $task = $p.StandardOutput.ReadAsync($buf, 0, $buf.Length)
            continue
        }
        # No output for a moment => program is waiting for input.
        if (([DateTime]::Now - $last).TotalMilliseconds -gt 400) {
            if ($idx -lt $inputs.Count) {
                $line = $inputs[$idx++]
                $p.StandardInput.WriteLine($line); $p.StandardInput.Flush()
                $segs.Add((New-Seg "$line`n" 'in'))
            }
            elseif (-not $stdinClosed) { $p.StandardInput.Close(); $stdinClosed = $true }
            $last = [DateTime]::Now
        }
        if ([DateTime]::Now -gt $deadline) {
            try { $p.Kill() } catch {}
            $segs.Add((New-Seg "`n[timed out]`n" 'err')); break
        }
    }
    $p.WaitForExit(2000) | Out-Null
    return , $segs
}

# --------------------------------------------------------------- render ---
function New-RoundRect([float]$x, [float]$y, [float]$w, [float]$h, [float]$r) {
    $g = New-Object System.Drawing.Drawing2D.GraphicsPath; $d = $r * 2
    $g.AddArc($x, $y, $d, $d, 180, 90)
    $g.AddArc($x + $w - $d, $y, $d, $d, 270, 90)
    $g.AddArc($x + $w - $d, $y + $h - $d, $d, $d, 0, 90)
    $g.AddArc($x, $y + $h - $d, $d, $d, 90, 90)
    $g.CloseFigure(); return $g
}
function C($hex) { [System.Drawing.ColorTranslator]::FromHtml($hex) }

function Save-TerminalPng($segs, [string]$title, [string]$exeName, [string]$path) {
    # ---- Build the session: prompt + command, program output, final prompt + cursor.
    $prompt = "PS $PromptPath> "
    $all = New-Object System.Collections.Generic.List[object]
    $all.Add((New-Seg $prompt 'prompt')); $all.Add((New-Seg '& ' 'op')); $all.Add((New-Seg "`".\$exeName`"`n" 'str'))
    foreach ($s in $segs) { $all.Add($s) }
    $tail = (($segs | ForEach-Object { $_.Text }) -join '')
    if ($tail.Length -and -not $tail.EndsWith("`n")) { $all.Add((New-Seg "`n" 'out')) }
    $all.Add((New-Seg $prompt 'prompt')); $all.Add((New-Seg ' ' 'cursor'))

    # ---- Split into lines of coloured runs.
    $lines = New-Object System.Collections.Generic.List[object]
    $cur = New-Object System.Collections.Generic.List[object]
    foreach ($s in $all) {
        $t = ($s.Text -replace "`r`n", "`n" -replace "`r", '') -replace "`t", '    '
        $parts = $t.Split([char]10)
        for ($i = 0; $i -lt $parts.Length; $i++) {
            if ($i -gt 0) { $lines.Add($cur); $cur = New-Object System.Collections.Generic.List[object] }
            if ($parts[$i].Length) { $cur.Add((New-Seg $parts[$i] $s.Kind)) }
        }
    }
    $lines.Add($cur)

    $maxCols = 0
    foreach ($l in $lines) { $c = 0; foreach ($r in $l) { $c += $r.Text.Length }; if ($c -gt $maxCols) { $maxCols = $c } }

    $px    = [System.Drawing.GraphicsUnit]::Pixel
    $font  = New-Object System.Drawing.Font($FontName, $FontPx, $px)
    $uiFnt = New-Object System.Drawing.Font('Segoe UI', 12, $px)
    $icon  = New-Object System.Drawing.Font($IconFont, 10, $px)
    $iconS = New-Object System.Drawing.Font($IconFont, 8, $px)
    $psFnt = New-Object System.Drawing.Font('Cascadia Mono', 8, [System.Drawing.FontStyle]::Bold, $px)
    $fmt   = [System.Drawing.StringFormat]::GenericTypographic
    $center = New-Object System.Drawing.StringFormat; $center.Alignment = 'Center'; $center.LineAlignment = 'Center'

    $tmp = New-Object System.Drawing.Bitmap 1, 1
    $mg = [System.Drawing.Graphics]::FromImage($tmp)
    $cw = $mg.MeasureString(('W' * 100), $font, [System.Drawing.PointF]::Empty, $fmt).Width / 100
    $mg.Dispose(); $tmp.Dispose()

    $W = [math]::Max($MinW, [math]::Ceiling($Pad * 2 + ($maxCols + 1) * $cw + 14))   # +14 = scrollbar gutter
    $H = $TabRowH + $Pad + $lines.Count * $LineH + $Pad + 4

    $bmp = New-Object System.Drawing.Bitmap ([int]($W * $Scale)), ([int]($H * $Scale)), ([System.Drawing.Imaging.PixelFormat]::Format32bppArgb)
    $g = [System.Drawing.Graphics]::FromImage($bmp)
    $g.ScaleTransform($Scale, $Scale)
    $g.SmoothingMode = 'AntiAlias'
    $g.TextRenderingHint = 'AntiAlias'
    $g.Clear([System.Drawing.Color]::Transparent)
    $B = { param($hex) New-Object System.Drawing.SolidBrush (C $hex) }

    # ---- Window + tab row
    $win = New-RoundRect 0.5 0.5 ($W - 1) ($H - 1) 8
    $g.FillPath((& $B $Theme.Body), $win)
    $g.SetClip($win)
    $g.FillRectangle((& $B $Theme.TabRow), 0, 0, $W, $TabRowH)

    # Active tab (same colour as terminal body, rounded top corners)
    $tabX = 8; $tabY = 8; $tabW = 240; $tabH = $TabRowH - $tabY
    $tab = New-Object System.Drawing.Drawing2D.GraphicsPath
    $tab.AddArc($tabX, $tabY, 16, 16, 180, 90); $tab.AddArc($tabX + $tabW - 16, $tabY, 16, 16, 270, 90)
    $tab.AddLine(($tabX + $tabW), ($tabY + $tabH + 1), $tabX, ($tabY + $tabH + 1)); $tab.CloseFigure()
    $g.FillPath((& $B $Theme.Body), $tab)
    $g.ResetClip()

    # PowerShell icon (blue tile with >_)
    $ix = $tabX + 12; $iy = $tabY + ($tabH - 16) / 2
    $g.FillPath((& $B '#2B5797'), (New-RoundRect $ix $iy 16 16 3))
    $g.DrawString('>_', $psFnt, (& $B '#FFFFFF'), (New-Object System.Drawing.RectangleF($ix, ($iy + 0.5), 16, 16)), $center)
    # Tab title + close
    $g.DrawString($title, $uiFnt, (& $B '#FFFFFF'), (New-Object System.Drawing.RectangleF(($ix + 24), $tabY, 170, $tabH)), (New-Object System.Drawing.StringFormat -Property @{ LineAlignment = 'Center' }))
    $g.DrawString([string][char]0xE8BB, $iconS, (& $B $Theme.Chrome), (New-Object System.Drawing.RectangleF(($tabX + $tabW - 30), $tabY, 20, $tabH)), $center)
    # New-tab "+" and dropdown chevron
    $g.DrawString([string][char]0xE710, $icon, (& $B $Theme.Chrome), (New-Object System.Drawing.RectangleF(($tabX + $tabW + 6), $tabY, 30, $tabH)), $center)
    $g.DrawString([string][char]0xE70D, $icon, (& $B $Theme.Chrome), (New-Object System.Drawing.RectangleF(($tabX + $tabW + 38), $tabY, 30, $tabH)), $center)
    # Caption buttons: minimise, maximise, close
    $glyphs = 0xE921, 0xE922, 0xE8BB
    for ($i = 0; $i -lt 3; $i++) {
        $g.DrawString([string][char]$glyphs[$i], $icon, (& $B '#FFFFFF'), (New-Object System.Drawing.RectangleF(($W - 46 * (3 - $i)), 0, 46, 32)), $center)
    }
    $g.DrawPath((New-Object System.Drawing.Pen (C $Theme.Border)), $win)

    # ---- Console text
    $brushes = @{}
    foreach ($k in 'out', 'in', 'prompt', 'op', 'str', 'err') { $brushes[$k] = & $B $Theme[$k] }
    $y = $TabRowH + $Pad
    foreach ($l in $lines) {
        $col = 0
        foreach ($r in $l) {
            if ($r.Kind -eq 'cursor') {   # Windows Terminal default "bar" cursor
                $g.FillRectangle((& $B '#FFFFFF'), ($Pad + $col * $cw), ($y + 1), 1.5, ($LineH - 3)); continue
            }
            $trim = $r.Text.TrimStart(' ')
            $col += $r.Text.Length - $trim.Length
            if ($trim.Length) { $g.DrawString($trim, $font, $brushes[$r.Kind], ($Pad + $col * $cw), $y, $fmt) }
            $col += $trim.Length
        }
        $y += $LineH
    }

    $bmp.Save($path, [System.Drawing.Imaging.ImageFormat]::Png)
    $g.Dispose(); $bmp.Dispose(); $font.Dispose(); $uiFnt.Dispose(); $icon.Dispose(); $iconS.Dispose(); $psFnt.Dispose()
}

# ----------------------------------------------------------------- main ---
$sources = Get-ChildItem $root -Filter 'practical*.cpp' |
    Sort-Object { [int]([regex]::Match($_.BaseName, '\d+').Value) }, BaseName |
    ForEach-Object {
        $safe = $_.BaseName -replace '[^\w]', '_'
        [pscustomobject]@{ File = $_; Base = $_.BaseName; Safe = $safe; ExeName = "$safe.exe" }
    }
if ($Only) { $sources = @($sources | Where-Object { $b = $_.Base; @($Only | Where-Object { $b -like "$_*" }).Count -gt 0 }) }
if (-not $sources) { throw 'No matching practical*.cpp files found.' }

$compiler = Get-Compiler
Write-Host "Compiler: $($compiler.Kind)  ($($compiler.Path))" -ForegroundColor DarkGray
Write-Host "Compiling $(@($sources).Count) file(s)..." -ForegroundColor Cyan
Build-All $sources $compiler

foreach ($s in $sources) {
    $exe = Join-Path $buildDir $s.ExeName
    if (-not (Test-Path $exe)) {
        Write-Host "  [FAIL] $($s.Base) - see outputs\.build\$($s.Safe).log" -ForegroundColor Red
        continue
    }

    $inputs = @()
    $inFile = Join-Path $inDir "$($s.Base).txt"
    if (Test-Path $inFile) {
        $inputs = ([IO.File]::ReadAllText($inFile) -replace "`r", '').Split([char]10)
        if ($inputs[-1] -eq '') { $inputs = $inputs[0..($inputs.Length - 2)] }   # drop final newline
    }

    $segs = Invoke-Session $exe $inputs
    $png = Join-Path $outDir "$($s.Base).png"
    Save-TerminalPng $segs 'Windows PowerShell' "$($s.Base).exe" $png
    Write-Host "  [ OK ] $($s.Base)  ->  outputs\$($s.Base).png" -ForegroundColor Green
}

# Clean up temporary build files so outputs\ contains only the screenshots.
Remove-Item $buildDir -Recurse -Force -ErrorAction SilentlyContinue

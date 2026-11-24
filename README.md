<div align="center">

# 🏛️ Object-Oriented Programming in C++
### Practical Laboratory Portfolio & Implementation Log

[![Language](https://img.shields.io/badge/Language-C%2B%2B17%20%2F%20C%2B%2B20-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://en.cppreference.com/)
[![Standard](https://img.shields.io/badge/Standard-ISO%2FIEC%2014882-blue?style=for-the-badge)](https://isocpp.org/)
[![Compiler](https://img.shields.io/badge/Compiler-GCC%20%7C%20Clang%20%7C%20MSVC-orange?style=for-the-badge)](https://gcc.gnu.org/)
[![Platform](https://img.shields.io/badge/Platform-Cross--Platform-lightgrey?style=for-the-badge)](https://github.com/makarandbobhate/object-oriented-programming-cpp)

<p align="center">
  A structured, modular laboratory repository illustrating fundamental-to-advanced paradigms of <b>Object-Oriented Programming (OOP)</b> in modern C++, focusing on real-world systems modeling, clean code architecture, and memory lifecycle discipline.
</p>

</div>

---

## 📌 Student & Academic Profile

| Attribute | Details |
| :--- | :--- |
| **Candidate Name** | **Makarand Pankaj Bobhate** |
| **Roll Number** | `09` |
| **Institution** | **MIT ADT University** |
| **Department / Class** | School of AI (SO AI) |
| **Division** | Division 5 |
| **Course Module** | Object Oriented Programming Systems (OOPS) |
| **Programming Language** | C++ |

---

## 🎯 Curriculum Objectives & Competencies

This laboratory suite targets mastery over foundational software engineering principles:
* **Encapsulation & Access Control:** Information hiding using `private`, `protected`, and `public` specifiers to safeguard state integrity.
* **Object Lifecycle Management:** Deterministic resource initialization via default, parameterized, and copy constructors; systematic destruction via RAII-compliant destructors.
* **Scope Resolution & Disambiguation:** Resolving namespace and attribute collisions using the implicit `this` pointer.
* **Polymorphic & Hierarchical Architecture:** Code reuse and extensible taxonomies via Single, Multilevel, and Hierarchical inheritance models.
* **Generic Programming & Templates:** Type-independent function and class templates enabling code reusability and compile-time polymorphism.

---

## 📑 Lab Practicals Index

| Practical | Core OOP Paradigm | Problem Statement & Specification | Code Source | Output Snapshot |
| :---: | :--- | :--- | :---: | :---: |
| **01** | **Classes & Objects** | **Digital Book Inventory System:** Standalone `Book` entity capturing ISBN, metadata, and price with secure I/O streams. | [`practical 1.cpp`](./practical%201/practical%201.cpp) | [📸 Output](./practical%201/practical%201.png) |
| **02** | **Array of Objects** | **College Record Digitization:** Array-driven database for record management, dynamic iteration, input validation, and search. | [`practical 2.cpp`](./practical%202/practical%202.cpp) | [📸 Output](./practical%202/practical%202.png) |
| **03** | **Data Encapsulation** | **HR Access Control System:** Private attribute isolation in an `Employee` entity with role-gated access methods enforcing authorization boundaries. | [`practical 3.cpp`](./practical%203/practical%203.cpp) | [📸 Output](./practical%203/practical%203.png) |
| **04** | **Constructors** | **Constructors Overloading:** Bookstore module evaluating explicit initialization paths using default and parameterized constructors. | [`practical 4.cpp`](./practical%204/practical%204.cpp)<br>*(Input: [`4_input.cpp`](./practical%204/practical%204_input.cpp))* | [📸 Output](./practical%204/practical%204.png)<br>*(Input: [📸 Output](./practical%204/practical%204_input.png))* |
| **05** | **The `this` Pointer** | **Online Admissions Portal:** Attribute-parameter identifier collision resolution within constructor scope using explicit `this->` reference. | [`practical 5.cpp`](./practical%205/practical%205.cpp)<br>*(Input: [`5_input.cpp`](./practical%205/practical%205_input.cpp))* | [📸 Output](./practical%205/practical%205.png)<br>*(Input: [📸 Output](./practical%205/practical%205_input.png))* |
| **06** | **Destructors & Lifecycle** | **Recruitment Pipeline Buffer:** Demonstrating deterministic memory release and notification events during stack unwinding and scope termination. | [`practical 6.cpp`](./practical%206/practical%206.cpp)<br>*(Input: [`6_input.cpp`](./practical%206/practical%206_input.cpp))* | [📸 Output](./practical%206/practical%206.png)<br>*(Input: [📸 Output](./practical%206/practical%206_input.png))* |
| **07** | **Single Inheritance** | **Academic Hierarchy:** Derivation of `Student` from base `Person`, inheriting personal attributes while augmenting academic-specific fields. | [`practical 7.cpp`](./practical%207/practical%207.cpp)<br>*(Input: [`7_input.cpp`](./practical%207/practical%207_input.cpp))* | [📸 Output](./practical%207/practical%207.png)<br>*(Input: [📸 Output](./practical%207/practical%207_input.png))* |
| **08** | **Multilevel Inheritance** | **Workforce Hierarchy:** Multi-tier architectural inheritance pattern extending `Person` ➔ `Employee` ➔ `Manager` across layered data planes. | [`practical 8.cpp`](./practical%208/practical%208.cpp)<br>*(Input: [`8_input.cpp`](./practical%208/practical%208_input.cpp))* | [📸 Output](./practical%208/practical%208.png)<br>*(Input: [📸 Output](./practical%208/practical%208_input.png))* |
| **09** | **Hierarchical Inheritance** | **Fleet Management System:** Single generalized base specification (`Vehicle`) branching into specialized domains (`Car`, `Truck`). | [`practical 9.cpp`](./practical%209/practical%209.cpp)<br>*(Input: [`9_input.cpp`](./practical%209/practical%209_input.cpp))* | [📸 Output](./practical%209/practical%209.png)<br>*(Input: [📸 Output](./practical%209/practical%209_input.png))* |
| **10** | **Function Templates** | **Generic Maximum Comparison:** Function template `myMax` evaluating maximum values across heterogeneous types (integers, floating-point numbers). | [`practical 10.cpp`](./practical%2010/practical%2010.cpp) | [📸 Output](./practical%2010/practical%2010.png) |
| **11** | **Function Templates** | **Generic Swap Utility:** In-place value exchange across data types using call-by-reference function template `mySwap`. | [`practical 11.cpp`](./practical%2011/practical%2011.cpp) | [📸 Output](./practical%2011/practical%2011.png) |
| **12** | **Class Templates** | **Generic Data Container:** Type-parameterized class template `Data` encapsulating and presenting arbitrary values (`int`, `double`, `string`). | [`practical 12.cpp`](./practical%2012/practical%2012.cpp) | [📸 Output](./practical%2012/practical%2012.png) |

---

## 🛠️ Build & Execution Instructions

Each practical is isolated in its own folder containing the source code, output screenshot, and sample inputs.

### Prerequisites
* **Compiler:** `g++` (MinGW-w64 on Windows or native GCC on Linux/macOS) / `clang++` / `MSVC (cl.exe)`
* **Terminal:** PowerShell, Command Prompt, or Bash

### Compilation Command

```bash
# General syntax
g++ -std=c++17 -Wall -Wextra "practical <N>/practical <N>.cpp" -o output

# Windows execution
./output.exe

# Linux/macOS execution
./output
```

#### Example (Practical 1):
```bash
g++ -std=c++17 "practical 1/practical 1.cpp" -o book_inventory
./book_inventory
```

---

## 📁 Repository Directory Structure

```text
object-oriented-programming-cpp/
├── .gitignore                   # Ignores build artifacts, executables (.exe, .o), and IDE configs
├── README.md                    # Comprehensive documentation and practical directory
├── practical 1/
│   ├── practical 1.cpp          # Source code: Classes & Objects
│   ├── practical 1.png          # Terminal execution screenshot
│   └── input.txt                # Sample input data
├── practical 2/
│   ├── practical 2.cpp          # Source code: Array of Objects
│   ├── practical 2.png          # Terminal execution screenshot
│   └── input.txt                # Sample input data
├── practical 3/
│   ├── practical 3.cpp          # Source code: Encapsulation & Access Control
│   └── practical 3.png          # Terminal execution screenshot
├── practical 4/
│   ├── practical 4.cpp          # Default & Parameterized Constructors
│   ├── practical 4_input.cpp    # Interactive Input Variant
│   ├── practical 4.png          # Baseline execution screenshot
│   ├── practical 4_input.png    # Interactive execution screenshot
│   └── input.txt                # Sample input data
├── practical 5/
│   ├── practical 5.cpp          # 'this' Pointer Disambiguation
│   ├── practical 5_input.cpp    # Interactive Input Variant
│   ├── practical 5.png          # Baseline execution screenshot
│   ├── practical 5_input.png    # Interactive execution screenshot
│   └── input.txt                # Sample input data
├── practical 6/
│   ├── practical 6.cpp          # Destructors & Scope Destruction
│   ├── practical 6_input.cpp    # Interactive Input Variant
│   ├── practical 6.png          # Baseline execution screenshot
│   ├── practical 6_input.png    # Interactive execution screenshot
│   └── input.txt                # Sample input data
├── practical 7/
│   ├── practical 7.cpp          # Single Inheritance
│   ├── practical 7_input.cpp    # Interactive Input Variant
│   ├── practical 7.png          # Baseline execution screenshot
│   ├── practical 7_input.png    # Interactive execution screenshot
│   └── input.txt                # Sample input data
├── practical 8/
│   ├── practical 8.cpp          # Multilevel Inheritance
│   ├── practical 8_input.cpp    # Interactive Input Variant
│   ├── practical 8.png          # Baseline execution screenshot
│   ├── practical 8_input.png    # Interactive execution screenshot
│   └── input.txt                # Sample input data
├── practical 9/
│   ├── practical 9.cpp          # Hierarchical Inheritance
│   ├── practical 9_input.cpp    # Interactive Input Variant
│   ├── practical 9.png          # Baseline execution screenshot
│   ├── practical 9_input.png    # Interactive execution screenshot
│   └── input.txt                # Sample input data
├── practical 10/
│   ├── practical 10.cpp         # Function Template (myMax)
│   └── practical 10.png         # Terminal execution screenshot
├── practical 11/
│   ├── practical 11.cpp         # Function Template (mySwap)
│   └── practical 11.png         # Terminal execution screenshot
└── practical 12/
    ├── practical 12.cpp         # Class Template (Data)
    └── practical 12.png         # Terminal execution screenshot
```

---

<div align="center">

Developed & maintained by **[Makarand Bobhate](https://github.com/makarandbobhate)**<br>
<sub>Released for academic reference and software engineering practice.</sub>

</div>

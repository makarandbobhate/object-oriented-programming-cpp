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

---

## 📑 Lab Practicals Index

| Practical | Core OOP Paradigm | Problem Statement & Specification | Code Source |
| :---: | :--- | :--- | :---: |
| **01** | **Classes & Objects** | **Digital Book Inventory System:** Design a standalone `Book` entity capturing ISBN, metadata, and price with secure I/O streams. | [`practical 1.cpp`](./practical%201.cpp) |
| **02** | **Array of Objects** | **College Record Digitization:** Array-driven database for record management, input parsing, dynamic iteration, and roll number search. | [`practical 2.cpp`](./practical%202.cpp) |
| **03** | **Data Encapsulation** | **HR Access Control System:** Private attribute isolation in an `Employee` entity with role-gated access methods enforcing authorization boundaries. | [`practical 3.cpp`](./practical%203.cpp) |
| **04** | **Constructors** | **Constructors Overloading:** Bookstore module evaluating explicit initialization paths using default and parameterized constructors. | [`practical 4.cpp`](./practical%204.cpp) |
| **05** | **The `this` Pointer** | **Online Admissions Portal:** Attribute-parameter identifier collision resolution within constructor scope using explicit `this->` reference. | [`practical 5.cpp`](./practical%205.cpp)<br>*(Input: [`5_input.cpp`](./practical%205_input.cpp))* |
| **06** | **Destructors & Lifecycle** | **Recruitment Pipeline Buffer:** Demonstrating deterministic memory release and notification events during stack unwinding and scope termination. | [`practical 6.cpp`](./practical%206.cpp)<br>*(Input: [`6_input.cpp`](./practical%206_input.cpp))* |
| **07** | **Single Inheritance** | **Academic Hierarchy:** Derivation of `Student` from base `Person`, inheriting personal attributes while augmenting academic-specific fields. | [`practical 7.cpp`](./practical%207.cpp)<br>*(Input: [`7_input.cpp`](./practical%207_input.cpp))* |
| **08** | **Multilevel Inheritance** | **Workforce Hierarchy:** Multi-tier architectural inheritance pattern extending `Person` ➔ `Employee` ➔ `Manager` across layered data planes. | [`practical 8.cpp`](./practical%208.cpp)<br>*(Input: [`8_input.cpp`](./practical%208_input.cpp))* |
| **09** | **Hierarchical Inheritance** | **Fleet Management System:** Single generalized base specification (`Vehicle`) branching into specialized domains (`Car`, `Truck`). | [`practical 9.cpp`](./practical%209.cpp)<br>*(Input: [`9_input.cpp`](./practical%209_input.cpp))* |

---

## 🛠️ Build & Execution Instructions

All practical files are self-contained and require standard ISO C++ compilation.

### Prerequisites
* **Compiler:** `g++` (MinGW-w64 on Windows or native GCC on Linux/macOS) / `clang++` / `MSVC (cl.exe)`
* **Terminal:** PowerShell, Command Prompt, or Bash

### Compilation Command

```bash
# General syntax
g++ -std=c++17 -Wall -Wextra "practical <N>.cpp" -o output

# Windows execution
./output.exe

# Linux/macOS execution
./output
```

#### Example (Practical 1):
```bash
g++ -std=c++17 "practical 1.cpp" -o book_inventory
./book_inventory
```

---

## 📁 Repository Directory Structure

```text
object-oriented-programming-cpp/
├── .gitignore               # Ignores build artifacts, executables (.exe, .o), and IDE configs
├── README.md                # Comprehensive documentation and practical directory
├── practical 1.cpp          # Practical 1: Classes & Objects
├── practical 2.cpp          # Practical 2: Array of Objects
├── practical 3.cpp          # Practical 3: Encapsulation & Data Hiding
├── practical 4.cpp          # Practical 4: Default & Parameterized Constructors
├── practical 5.cpp          # Practical 5: 'this' Pointer Disambiguation
├── practical 5_input.cpp    # Practical 5: Interactive Input Variant
├── practical 6.cpp          # Practical 6: Destructors & Scope Destruction
├── practical 6_input.cpp    # Practical 6: Interactive Input Variant
├── practical 7.cpp          # Practical 7: Single Inheritance
├── practical 7_input.cpp    # Practical 7: Interactive Input Variant
├── practical 8.cpp          # Practical 8: Multilevel Inheritance
├── practical 8_input.cpp    # Practical 8: Interactive Input Variant
├── practical 9.cpp          # Practical 9: Hierarchical Inheritance
└── practical 9_input.cpp    # Practical 9: Interactive Input Variant
```

---

<div align="center">

Developed & maintained by **[Makarand Bobhate](https://github.com/makarandbobhate)**<br>
<sub>Released for academic reference and software engineering practice.</sub>

</div>

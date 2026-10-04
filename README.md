 Municipal Financial Management System (MFMS)

PAP521S Project

A modular *Municipal Financial Management System (MFMS)* developed in the *C programming language* as part of the PAP521S project.

The system provides a menu-driven interface for managing key municipal information, including employees, budgets, suppliers, assets, and management reports.

---

Table of Contents

* [Project Overview](#project-overview)
* [Objectives](#objectives)
* [Features](#features)
* [System Modules](#system-modules)
* [Technologies Used](#technologies-used)
* [Project Structure](#project-structure)
* [Requirements](#requirements)
* [Compilation and Execution](#compilation-and-execution)
* [System Usage](#system-usage)
* [Input Validation](#input-validation)
* [Testing](#testing)
* [Version Control](#version-control)
* [Contributors](#contributors)
* [Limitations](#limitations)
* [Future Improvements](#future-improvements)
* [Academic Information](#academic-information)

---

Project Overview

The Municipal Financial Management System is a command-line application designed to demonstrate how a municipality can manage and organize important operational and financial information using a structured software system.

The application uses a modular design, with different source and header files responsible for specific areas of the system.

The main areas of management are:

* Employees
* Budgets
* Suppliers
* Assets
* Reports

The project demonstrates the practical application of C programming concepts including functions, structures, arrays, conditional statements, loops, input validation, modular programming, and header files.

Objectives

The main objectives of the project are to:

1. Develop a functional municipal management system using C.
2. Apply structured and modular programming principles.
3. Demonstrate the use of functions and data structures.
4. Separate functionality into appropriate .c and .h files.
5. Provide a clear and user-friendly command-line interface.
6. Implement appropriate input validation and error handling.
7. Demonstrate the management of municipal financial and operational information.
8. Use Git and GitHub for version control and collaborative development.

Features

The system provides the following functionality:

Employee Management

* Add employee records
* Display employee records
* Remove employee records
* Manage employee information

Budget Management

* Add and manage budget information
* Display budget records
* Manage budget allocations
* Perform relevant budget-related calculations

Supplier Management

* Add supplier records
* Display supplier information
* Remove supplier records
* Manage supplier information

Asset Management

* Add asset records
* Display asset information
* Remove asset records
* Manage municipal asset information

Reports

* Generate system reports
* Display relevant management information
* Provide summaries of stored information

---

System Modules

The project is divided into separate modules to make the program easier to understand, maintain, and extend.

| Module          | Purpose                                      |
| --------------- | -------------------------------------------- |
| main.c        | Controls program execution and the main menu |
| employee.c/.h | Employee management functionality            |
| budget.c/.h   | Budget management functionality              |
| supplier.c/.h | Supplier management functionality            |
| asset.c/.h    | Asset management functionality               |
| reports.c/.h  | Report generation and management             |

---

Technologies Used

* *Language:* C
* *C Standard:* C99
* *Compiler:* GCC
* *Interface:* Command-Line Interface (CLI)
* *Version Control:* Git
* *Repository Hosting:* GitHub

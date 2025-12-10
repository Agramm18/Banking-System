# Banking System Simulation

This project is a simulation of a traditional banking system combined with modern online banking features (similar to PayPal or Apple Pay).
It was developed to learn and practice C++ and will later be extended with a GUI using Qt.

## Used Technologies

1. **C++** as the main programming language
2. **Python** for validation and auxiliary processing
3. **JSON** for data exchange between C++ and Python
4. **SQLite** as the database system

## Used Libraries

1. **libsodium** – password hashing and encryption
2. **datetime / date (Python)** – date validation
3. **pycountry** – country code lookup for generating valid bank card information

## Required Libraries & Tools

### 1. vcpkg

* libsodium

### 2. Python & pip packages

* json (built-in)
* datetime & date (built-in)
* pycountry (`pip install pycountry`)

### 3. SQL Connector for C/C++

## Database Logic

Main Profile
 └── User Account
      └── Card Information
           └── Card Movements & Changes

## Core Structure

System Profile
 └── Account
      └── Card Data
           └── Card Movement (Transactions)

## Main Architecture

main.cpp
 └── windowsBuild.bat (script to build the project)
      └── /build (compiled .exe, Python scripts, JSON files)
           └── ApplicationController.cpp (controls the entire system)
                └── Login / Registration
                     └── Two-Factor Authentication
                          └── menu.cpp (controller for all classes & functions)

## File Structure

main.cpp
windowsBuild.bat
/build
   ├── main.exe
   ├── Python files
   └── JSON files
/include
   └── header files (.h)
/src
   └── source files (.cpp)


## Current Features

### Core

* Account creation
* Profile creation
* Main menu

## Planned Features

### Core

* Login / Logout
* Full 2FA integration
* Database connection
* Extended main menu

### Banking

* Create bank cards (Debit, Giro, Credit)
* Deposit, withdraw, transfer
* Set and edit availability and limits
* Create and manage standing orders
* Set and adjust overdraft limits

## Planned Technologies

* Full database integration
* Qt-based GUI

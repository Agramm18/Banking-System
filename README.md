# Banking System Simulation

This project is a simulation of a traditional banking system combined with modern online banking features (similar to PayPal, Apple Pay, etc.).  
It was developed to learn and practice C++ and will later be extended with a GUI using Qt.

# Used Technologies

1. C++ as the main language
2. Python for Simple Validation and data handeling
3. JSON to store data and send it to python
4. SQL-Lite for the database

# used libaries

1. libsodium (for password hashing and encryption)
2. datetime & date to validate the date from the user b-day
3. pycountries (to get the country code to generate valid bank cards)

# Needed Libaries & Tools

1. vcpkg
  |
  --> Libsodium

2. pip & python
 |
 --> json
 --> date & datetime
 --> pycountries (pip install pycountries)

3. SQL Connector for C/C++

# Database Logic

Main Profile
|
--> User Account
  |
  --> Card Information
    |
    --> Card moovments & changes

# Core Split

System Profile
|
--> Account
  |
  --> Card Data
    |
    --> Card Moovment (Transaction)

# Main Architecture

main.cpp
|
--> windowsBuild.bat (To Compile the project right)
  |
  --> /build (folder to compile the .exe)
    |
    --> ApplicationController.cpp (Controlls the whole system)
      |
      --> Login/Registration
        |
        --> 2FA
          |
          --> menu.cpp (Acctual Controller to call each class & function)

# File Structure

- main.cpp
- windowsBuild.bat
  |
  --> build (compiler folder with the main.exe the python files and the json files)
  --> include (folder with the .h files)
  --> src (folder with the .cpp files)

# current features

- Core
  - Create Account
  - Create Profile
  - Main Menue
  
# planned Features

- Core
  - Login/ Logout, 2FA, Database
  - Main Menu

- Banking
  - Create Banking Cards (Debit Card, Giro Card, Credit Card)
  - Deposit money, withdraw money, transfer money, add and edit availability, limits
  - Create & adjust standing orders
  - Set & adjust overdraft limit

# planned technologies

- Database
- GUI
# Banking System Simulation

This project is a simulation of a traditional banking system combined with modern online banking features (similar to PayPal, Apple Pay, etc.).  
It was developed to learn and practice C++ and will later be extended with a GUI using Qt.

---

## Features Overview

### **Authentication**
- **Login / Registration**  
  Includes user authentication and secure profile creation.

---

## User Actions
- **Create User**  
  Create a new user profile within the banking system.
- **Select Bankcard Type**  
  Choose between available card types (e.g., debit or credit).

---

## Card Generation System

The project includes a fully featured card generation module that simulates realistic banking cards with all required components.  
It supports creating, configuring, and validating new cards.

### **Card Configuration**
- **Set Bank Name**  
  Assigns the issuing bank’s name.
- **Set Card Type**  
  Selects the card type (Visa, Girocard, Credit Card).
- **Set Card Status**  
  Defines whether the card is active, blocked, or pending activation.

### **Card Data Generation**
- **Generate BIC**  
  Creates a valid Bank Identifier Code.
- **Generate Account Number**  
  Generates a numerical account identifier.
- **Generate BLZ**  
  Produces a German bank code (Bankleitzahl).
- **Generate CVV**  
  Generates a secure 3-digit CVV (credit cards only).
- **Set Expiration Date**  
  Assigns a realistic expiration date (MM/YY).
- **Generate IBAN**  
  Builds a valid IBAN using bank code, account number, and checksum logic.

### **Security Setup**
- **Set PIN**  
  Creates a secure PIN for the card.
- **Set PUK**  
  Generates a recovery PUK used when the PIN is entered incorrectly multiple times.

---

## Account Actions
- **Add Money**  
  Deposit funds into the account.
- **Withdraw Money**  
  Withdraw funds while respecting account limits.
- **Transfer Money**  
  Transfer funds to another account.
- **Add Standing Order**  
  Create automated recurring payments.

---

## Loans & Limits
- **Take Out a Loan**  
  Request and receive a loan under predefined conditions.
- **Change Debit Limit**  
  Adjust the maximum debit card transaction limit.
- **Change Overdraft Limit**  
  Modify how far the account may go into negative balance.

---

## Security & System
- **Change PIN**  
  Update the card's security PIN.
- **Block Card**  
  Block a card to prevent unauthorized usage.
- **Generate Cards / Delete Cards**  
  Create new bank cards or delete existing ones.

---

## Database
A database layer will be integrated in future versions to store user profiles, cards, transactions, and system data persistently.

---

## Future Plans
- Full GUI implementation using **Qt**
- Persistent database integration
- More detailed transaction history
- Support for additional card types (credit, prepaid, virtual)
- Extended security and encryption features

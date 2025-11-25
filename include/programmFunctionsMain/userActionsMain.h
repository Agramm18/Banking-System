#ifndef userActions_H
#define userActions_H
#include <iostream>

//Define Classes for user Actions

class UserLogic {
    
    public:

    void collectUserData();
    void selectBankcardType();

    void createUser();
    
    void createPin();
    void createPuk();

    void generateIBAN();
    void generateBIC();
    void generateExpirationDate();
};

class AccountActions {
    public:

    void AddMoney();
    void WithdrawMoney();
    void TransferMoney();

    void AddStandingOrder();
    
};

class LoanAndLimits {
    public:

    void TakeOutALoan();
    void changeDebitLimit();
    void changeOverdraftLimit();
};

class SecurityAndSystem {
    public:

    void ChangePin();
    void BlockCard();
};

class DisplayInformation {
    public:

    void DisplayAccountDetails();
    void DisplaySecurityInformation();

    void DisplayAccountBalance();
    void DisplayTransferActions();
    void DisplayStandingOrders();
    void DisplayOutstandingPayments();
    void DisplayYourCards();
};

#endif
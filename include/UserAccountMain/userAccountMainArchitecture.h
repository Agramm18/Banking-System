#ifndef userAccountMainArchitecture_H
#define userAccountMainArchitecture_H

#include <string>
#include <chrono>

//Define the main structure how your account and card will be created

class generateProfile {
    //Generate the Main Profile
    public:

    void setAccountName(); //Set the profile name
    void setProfileEmail(); //Set the Main E-Mail for the profile
    void setProfilePhoneNumber(); //Set the Main Phone Number for the Profile
    void setProfilePWSD(); //Set the Password for your Account
    
};

class createUser {
    //Generate the User Account for your Cards
    public:

    //Global Variables

    std::string FullName;

    //Create the user
    void setGenerallName(); //Set the name from the user
    void setBirthday(); //Set the birthday from the user
    void setCardAgeType(); //Validate if its an adult or child bank card

    void setAccountEmail(); //Sets your E-Mail Adress
    void setAccountPhonenumber(); //Void sets your phone number
    
    void generateUserID(); //Generates your User ID
};

class generateBankingCard {
    public:

    //Generates your Banking Card

    void setBankName(); //Sets the name from the bank
    void setCardType(); //Choose the card type vis, giro usw.
    void setCardStatus(); //Set the card status and if its active or not

    void generateBIC(); //Generate your BIC
    void generateAccountNumber(); //Sets the Number from your Card Account
    void generateBLZ(); //Generate the BLZ
    void generateCVV(); //Generate Secret Number (only by credit cards)
    void setExpirationDate(); //Set the expiration date from your card
    
    void generateIBAN(); //Generate your IBAN

    void setPIN(); //Sets your PIN
    void setPUK(); //Set your PUK
};

#endif
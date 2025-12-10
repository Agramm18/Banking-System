#ifndef GENERATOR_H
#define GENERATOR_H

#include <string>

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
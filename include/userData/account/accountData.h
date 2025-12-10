#ifndef ACCOUNT_DATA_H
#define ACCOUNT_DATA_H

#include <string>;

class account {
    //Generate the User Account 

    private:
    //Global Variables

    std::string FullName;
    std::string EmailAdress;
    std::string PhoneNumber;
    
    struct Birthday {
        int day;
        int month;
        int year;
    };

    Birthday Bday;
    std::string AccountID;
    bool AgeType;
    std::string AgeCardType;

    public:

    //Create the user
    void setGenerallName(); //Set the name from the user
    void setBirthday(); //Set the birthday from the user
    void setCardAgeType(); //Validate if its an adult or child bank card

    void setAccountEmail(); //Sets your E-Mail Adress
    void setAccountPhonenumber(); //Void sets your phone number
    
    void generateUserID(); //Generates your User ID
};

#endif
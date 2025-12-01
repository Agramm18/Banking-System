#include <UserAccountMain/userAccountMainArchitecture.h>

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void generateProfile::setAccountName() {
    //Set your Account Namet for the programm

    string UserName;

    try {
        cout <<"\nPlease choose a Username for your Profile: ";

        getline(cin, UserName);

        if (UserName.empty()) {
            throw runtime_error("The User name can't be empty");
        } else {
            AccountName = UserName;
            cout <<"\nThe Username for your Profile where set sucsessfully" <<endl;
            cout <<"The Username you setted is: " << UserName <<endl;
        }
    } catch(runtime_error &e) {
        cout <<"There is an invalid username" <<endl;
        cout <<"The error is: " <<e.what() <<endl;
    }
}

void generateProfile::setProfileEmail() {
    //Set your Account Email

    string UserEmail;
    try {
        cout <<"\nPlease set an Email for your Profile: ";
        getline(cin, UserEmail);

        if (UserEmail.empty()) {
            throw runtime_error("The Email for your Account can't be empty");
        } else if (UserEmail.find('@') == string::npos) {
            throw runtime_error("Invalid Email missing @");
        } else if (UserEmail.find('.') == string::npos) {
            throw runtime_error("Invalid Email missing . [.de, .com]");
        } else {
            AccountEmailAdress = UserEmail;
            cout <<"\nThe Email Adress for your Profile where setted sucsessfully" <<endl;
            cout <<"The Email Adress you setted is: " <<UserEmail <<endl;
        }
    } catch (runtime_error &e) {
        cout <<"Invalid Account email detected";
        cout <<"The error is: " << e.what() <<endl;
    }
}


void generateProfile::setProfilePhoneNumber() {
    //Set the Phone Number for your Account

    string UserPhoneNumber;

    try {
        cout <<"\nPlease set a Phone Number for your Profile: ";
        getline(cin, UserPhoneNumber);

        if (UserPhoneNumber.empty()) {
            throw runtime_error("Invalid phone number please type in a phone number");
        } else if (UserPhoneNumber[0] != '+') {
            throw runtime_error("Invalid phone number the phone number must start with + [+49, +43]");
        } else {
            AccountPhoneNumber = UserPhoneNumber;
            cout <<"\nThe Phonenumber for your Profile where setted sucsessfully" <<endl;
            cout <<"The Phone Number you setted is: " << UserPhoneNumber <<endl;
        } 
    } catch (runtime_error &e) {
            cout <<"The Phonenumber is invalid";
            cout <<"The error is: " <<e.what();
    }

}


void generateProfile::setProfilePWSD() {
    //Set the Password from your Profile

    string UserPWSD;
    bool isValid = true;

    try {
        cout <<"\nPlease set a Password for your Profile: ";
        getline(cin, UserPWSD);

        if (UserPWSD.length() < 1 || UserPWSD.length() > 15) {
            throw runtime_error("Invalid Password lengh please choose a valid Password [lenght = 1-15]");
            isValid = false;

            //To be continued
        }
    }  catch (runtime_error &e) {
            cout <<"The password is invalid";
            cout <<"The error is: " << e.what() <<endl;
    }
}
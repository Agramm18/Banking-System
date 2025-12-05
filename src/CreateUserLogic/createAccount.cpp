//Include imports to use other files
#include <UserAccountMain/userAccountMainArchitecture.h>

#include <iostream>
#include <string>
#include <limits>
#include <fstream>

#include <nlohmann/json.hpp>
using json = nlohmann::json;



using namespace std;
using namespace std::chrono;

//Create A new User

void createUser::setGenerallName() {
    //Set the generall name
    string firstName;
    string lastName;

    try {
        cout << "Please type in your first name: " <<endl;
        getline(cin, firstName);

        cout << "Please type in your last name: " <<endl;
        getline(cin, lastName);

        //Catch if lname or fname are empty and throw an error 
        if (firstName.empty() || lastName.empty()) {
            throw runtime_error("The first and last name from the user can't be empty please type in your first and last name or a runtime error will happend");
        } else {
            FullName = firstName + " " + lastName;  //Set the name for the user if fname and lname are not empty
            cout <<"The name for the user where sucsessfuly set";
        }

    } catch (runtime_error &e) {
            cout <<"There is an error in the name evalutation from the user" <<endl;
            cout <<"The error is: " <<e.what() <<endl;
        }
}

void createUser::setBirthday() {
    //Set the birthday from the user
    
    string bdayDay;
    string bdayMonth;
    string bdayYear;

    try {

        json data;

        //cin int fix
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout <<"Please type in the day when you where born: ";
        getline(cin, bdayDay);

        cout <<"Please type in the month when you where born: ";
        getline(cin, bdayMonth);

        cout <<"Please type in the year when you where born: ";
        getline(cin, bdayYear);

        if (bdayDay.empty() || bdayMonth.empty() || bdayYear.empty()) {
            throw runtime_error("The bday can't be empty");
        } else {
            //Convert input to int
            int bdayDayINT = stoi(bdayDay);
            int bdayMonthINT = stoi(bdayMonth);
            int bdayYearINT = stoi(bdayYear);

            cout<<"\nJSON-File will be generated";

            //Set Data
            data["day"] = bdayDayINT;
            data["month"] = bdayMonthINT;
            data["year"] = bdayYearINT;
            data["final-bday"] = nlohmann::json::array();
            data["date-value"] = false;

            //Genearte .json
            std::ofstream file("user_bday.json");

            //Error handeling
            if (!file.is_open()) {
                throw runtime_error("The JSON where not be created");
            }

            file << data.dump(4);
            file.close();

            cout <<"Python will now validate the bday and update the .json";
            system("python validate_bday.py"); //execute .py

            std::ifstream readfile("user_bday.json");
            readfile >> data; //load data

            if (data["date-value"].get<bool>()) {

                auto b = data["final-bday"];

                cout << "The bday is valid: "
                    << b[0].get<int>() << "."
                    << b[1].get<int>() << "."
                    << b[2].get<int>() << "\n";

                Bday.day = b[0].get<int>();
                Bday.month = b[1].get<int>();
                Bday.year = b[2].get<int>();

            } else {
                cout << "The birthday has an invalid date format\n";
            }
        }

    } catch (runtime_error &e) {
        cout <<"There is an error in the bday evaluaton please try again";
        cout <<"The error is: " << e.what() <<endl;
    }
}

void createUser::setAccountEmail() {
    //Set the account email
    string email;

    try {

        cout <<"Please type in your E-Mailadress: " <<endl;
        getline(cin, email);

        //Catch if email is empty
        if (email.empty()) {
            throw runtime_error("Your E-Mail cant't be empty");
        } else {
            EmailAdress = email; //set email
        }

    } catch (runtime_error &e) {
        cout <<"An error where detected" <<endl;
        cout <<"The error is: " << e.what() <<endl;
    }

};

void createUser::setAccountPhonenumber() {
    //Set the phone number for your account

    cout <<"Please note that only [+49 123456789] is the allowed format" <<endl;

    string phone;

    try {
        cout <<"Please type in your phone number: " <<endl;
        getline(cin, phone);

        //check if number is empty
        if (phone.empty()) {
            throw runtime_error("Please type in a phone number");
            //Check if number is valid
        } else if (phone[0] != '+') {
            throw runtime_error("Invalid phone number detected please type in valid number");
            //Check if lenght is valid
        } else if (phone.length() > 16 || phone.length() < 2 ) {
            throw runtime_error("Please type in a valid number the number can't be less than 1 or bigger than 16");
        } else {
            //set number if number is valid
            PhoneNumber = phone;
        }

    } catch (runtime_error &e) {
        cout <<"There is an error somewhere" <<endl;
        cout <<"The error is: " << e.what() <<endl;
    }

}
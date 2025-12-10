//Include imports to use other files
#include <userData/account/accountData.h>

#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <random>
#include <cctype>
#include <unordered_set>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

using namespace std;
using namespace std::chrono;

//Create A new User

void account::setGenerallName() {
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

void account::setAddress() {
    //Set the Address from the User

    string city;

    string streetname;
    string houseNumber;

    string postalCode;

    string county;
    string country;

    try {
        cout <<"Please type in your city name: ";
        getline(cin, city);

        cout << "Please type in your streetname: ";
        getline(cin, streetname);

        cout <<"Please type in your house number";
        getline(cin, houseNumber);

        cout <<"Please type in your postal code: ";
        getline(cin, postalCode);

        cout <<"Please type in your county: ";
        getline(cin, county);

        cout <<"Please type in your country: ";
        getline(cin, country);

        if (city.empty() || streetname.empty() || houseNumber.empty() || postalCode.empty() || county.empty() || country.empty()) {
            throw runtime_error("One of the fields is empty please try again");
        } else {

            //Make the first letter in the country upper and the rest lower
            for (char &c : country) {
                c = tolower(c);
            }
            country[0] = toupper(country[0]);

            cout <<"The JSON to set the right Country Code will be generated" <<endl;

            //Set Data
            json data;
            data["country"] = country;
            data["country-code"] = "default";

            //Generate JSON-File

            std::ofstream file("set_country_code.json");
            if (!file.is_open()) {
                throw runtime_error("The JSON could not be created");
            }
            
            file << data.dump(2);
            file.close();

            cout <<"\nPython will now set the right Country Code based on your country";
            system("python set_country_code.py");

            //load updated json
            std::ifstream readfile("set_country_code.json");
            readfile >> data;

            //Update the struct
            AddressData.city = city;
            AddressData.houseNumber = houseNumber;
            AddressData.postalCode = postalCode;
            AddressData.county = county;
            AddressData.country = country;
            AddressData.countryCode = data["country-code"];

            cout <<"All data from your address information where set sucsessfully"<<endl;

        }
    } catch (runtime_error &e) {
        cout <<"The error is: " <<e.what() <<endl;
    }

}

void account::setBirthday() {
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
        }  else {
    // Convert input to int
    int bdayDayINT = stoi(bdayDay);
    int bdayMonthINT = stoi(bdayMonth);
    int bdayYearINT = stoi(bdayYear);

    cout << "\nJSON-File to validate the date and set the age type will be generated";

    // Set Data
    data["day"] = bdayDayINT;
    data["month"] = bdayMonthINT;
    data["year"] = bdayYearINT;
    data["final-bday"] = nlohmann::json::array();
    data["date-value"] = false;

    // Generate JSON file
    std::ofstream file("user_bday.json");

    if (!file.is_open()) {
        throw runtime_error("The JSON could not be created");
    }

    file << data.dump(4);
    file.close();

    cout << "\nPython will now validate the bday and update the .json\n";
    system("python validate_bday.py");

    // Load updated JSON
    std::ifstream readfile("user_bday.json");
    readfile >> data;

    if (data["date-value"].get<bool>()) {

        auto b = data["final-bday"];

        cout << "The birthday is valid: "
            << b[0].get<int>() << "."
            << b[1].get<int>() << "."
            << b[2].get<int>() << "\n";

        Bday.day = b[0].get<int>();
        Bday.month = b[1].get<int>();
        Bday.year = b[2].get<int>();

        // -------------------------------------------
        //  GET AGE TYPE (True = adult, False = minor)
        // -------------------------------------------
        bool AgeType = data["age-type"].get<bool>();   // default → wird in Python überschrieben

        if (AgeType) {
            cout << "User is adult (18+)\n";
        } else {
            cout << "User is underage (<18)\n";
        }

            } else {
                cout << "The birthday has an invalid date format\n";
            }
        }

    } catch (runtime_error &e) {
        cout <<"There is an error in the bday evaluaton please try again";
        cout <<"The error is: " << e.what() <<endl;
    }
}

void account::setAccountEmail() {
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

void account::setAccountPhonenumber() {
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

void account::setCardAgeType() {
    //Set the Age Type

    try {
        if (AgeType) {
            AgeCardType = "Adult";
            cout <<"The User gets an Adult Account";
        } else if (!AgeType) {
            AgeCardType = "Child";
            cout <<"The User is underage he gets an Child Account";
        } else {
            throw runtime_error("The Age verification didn't work");
        }
    } catch(runtime_error &e) {
        cout <<"There is an error: " <<e.what();
    }
}

void account::generateUserID() {
    //Generate the User ID

    cout <<"Your User ID will now be generated"<<endl;

    //Generate random number in range 10
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 25);
    unordered_set<int> uniqueNumbers;

    while (uniqueNumbers.size() < 10) {
        int num = dist(gen);
        uniqueNumbers.insert(num);
    }

    for (int n : uniqueNumbers) {
        cout <<"The generated numbers are: " <<n <<endl;
    }

    //Generate lowercase letters in range 5
    uniform_int_distribution<> lowerDist(0, 25);
    unordered_set<int> lowerSet;

    while(lowerSet.size() < 5) {
        int num = lowerDist(gen);
        lowerSet.insert(num);
    }

    cout <<"The generated lower chars are: ";
    for (int n : lowerSet) {
        char letter = 'a' + n;
        cout << letter << " ";
    }

    cout << endl;

    //Generate uppercase letters in range 5
    uniform_int_distribution<> upperDist(0, 25);
    unordered_set<int> upperSet;

    while(upperSet.size() < 5) {
        int num = upperDist(gen);
        upperSet.insert(num);
    }

    cout << "Uppercase chars are: ";
    for (int n : upperSet) {
        char letter = 'A' + n;
        cout << letter << " ";
    }
    cout << endl;


    //Generate the User ID based on the random number the random upper and lowercased chars

    vector<string> UserID;

    //Add the Numbers
    for (int n : uniqueNumbers) {
        UserID.push_back(to_string(n));
    }

    //Add the lowercase chars
    for (int n : lowerSet) {
        char letter = 'a' + n;
        UserID.push_back(string(1, letter));
    }

    //Add the uppercase chars
    for (int n : upperSet) {
        char letter = 'A' +  n;
        UserID.push_back(string(1, letter));
    }

    try {
        //Check if lenght = 20 (random_numbers = 10, random_upper = 5, random_lower = 5)
        if (UserID.size() < 20) {
            throw runtime_error("The size is invalid it should be 20");
        } else {
            //Generate a random id with shuffle
            shuffle(UserID.begin(), UserID.end(), gen);
        }
    } catch (runtime_error & e) {
        cout <<"The error is: " << e.what() <<endl;
    }

    string GeneratedID;
    for (const string e : UserID) {
        GeneratedID += e;
    }

    cout <<"The User ID where Generated Sucsessfully";
    AccountID = GeneratedID;
}
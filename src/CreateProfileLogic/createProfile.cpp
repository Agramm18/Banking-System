#include <UserAccountMain/userAccountMainArchitecture.h>

#include <iostream>
#include <string>
#include <cctype>
#include <ctype.h>
#include <sodium.h>

using namespace std;

void generateProfile::setProfileName() {
    //Set your Account Namet for the programm

    string UserName;

    try {
        cout <<"\nPlease choose a Username for your Profile: ";

        getline(cin, UserName);

        if (UserName.empty()) {
            throw runtime_error("The User name can't be empty");
        } else {
            ProfileName = UserName;
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
            ProfileEmailAdress = UserEmail;
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
            ProfilePhoneNumber = UserPhoneNumber;
            cout <<"\nThe Phonenumber for your Profile where setted sucsessfully" <<endl;
            cout <<"The Phone Number you setted is: " << UserPhoneNumber <<endl;
        } 
    } catch (runtime_error &e) {
            cout <<"The Phonenumber is invalid";
            cout <<"The error is: " <<e.what();
    }

}

void generateProfile::generateProfilePWSD() {
    //Set the Password from your Profile

    string UserPWSD;
    string UserPWSDHashed;

    bool isValid = false;

    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;

    try {
        cout << "\nPlease set a Password for your Profile: "; //Get the UserPWSD
        getline(cin, UserPWSD);

        //Check if pwsd length is valid
        if (UserPWSD.length() < 1 || UserPWSD.length() > 10) {
            throw runtime_error("Invalid Password length please choose a valid Password [length = 1-10]");
        }

        //Analyze pwsd
        for (char c : UserPWSD) { 
            if (std::isupper(c)) hasUpper = true;
            else if (std::islower(c)) hasLower = true;
            else if (std::isdigit(c)) hasDigit = true;
            else if (std::ispunct(c)) hasSpecial = true;
        
        //Catch error if the password is not valid
        } if (!hasUpper) {
            throw runtime_error("The Password is invalid the password must contain atleast one upper case letter");
        } else if (!hasLower) {
            throw runtime_error("The Password is invalid the password must contain at least one lower letter");
        } else if (!hasDigit) {
            throw runtime_error("The Password is invalid the password must contain at least one number");
        } else if (!hasSpecial) {
            throw runtime_error("The Password is invalid the password must contain at least one special letter");
        } else {
            //Seth the valid to true if password is correct
            isValid = true;
        } if (isValid) {
            ProfilePasswordPlain = UserPWSD; //Set the Profile Password
            cout <<"\nThe Password is set sucsessfully";
            cout <<"Your Password will now be hashed"<<endl;
        }

    } catch (runtime_error &e) {
        cout << "The password is invalid";
        cout << "The error is: " << e.what() << endl;
    }
}

void generateProfile::hashProfilePWSD() {
    //Hash the password with sodium

    //Initialise Sodium
    if (sodium_init() < 0) {
        throw runtime_error("Failed to initialize Libsodium");
    }

    //Call obj from AccountPassword()
    std::string plainPWSD = ProfilePasswordPlain;

    unsigned char key[32]; //Hash Byte lenght
    unsigned char salt[crypto_pwhash_SALTBYTES]; //Fit SALT to BYTE [32]

    //Generate SALT
    randombytes_buf(salt, sizeof salt);

    //Generate HASH
    if (crypto_pwhash(
        key, sizeof key,
        plainPWSD.c_str(), plainPWSD.length(),
        salt,
        crypto_pwhash_OPSLIMIT_INTERACTIVE,
        crypto_pwhash_MEMLIMIT_INTERACTIVE,
        crypto_pwhash_ALG_DEFAULT) != 0)
    {
        throw runtime_error("Hashing failed");
    } else {
        cout <<"The Password hashed sucsessfully";
    }

    //Convert SALT and HASH back to str

    //Convert hash back
    char hash_b64[sodium_base64_ENCODED_LEN(sizeof key, sodium_base64_VARIANT_ORIGINAL)];
    sodium_bin2base64(hash_b64, sizeof hash_b64, key, sizeof key, sodium_base64_VARIANT_ORIGINAL);

    //Convert SALT back

    char salt_b64[sodium_base64_ENCODED_LEN(sizeof salt, sodium_base64_VARIANT_ORIGINAL)];
    sodium_bin2base64(salt_b64, sizeof salt_b64, salt, sizeof salt, sodium_base64_VARIANT_ORIGINAL);

    ProfilePasswordHash = hash_b64; //Login & Registration
    ProfilePasswordSalt = salt_b64; // Database

    cout<<"\nThe Password where Hashed sucsessfully";
    cout <<"The SALT is generated sucsessfully";
    cout <<"Your Profile is now settet sucssessfully and complete";
    cout <<"The data will be added to the database";
    cout <<"Have fun with my project" <<endl;
}
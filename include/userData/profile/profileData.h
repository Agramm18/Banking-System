#ifndef PROFILE_DATA_H
#define PROFILE_DATA_H

#include <string>

class generateProfile {
    //Generate the Main Profile
    private:
    std::string ProfileName;
    std::string ProfileEmailAdress;
    std::string ProfilePhoneNumber;
    std::string ProfilePasswordPlain;
    std::string ProfilePasswordHash;
    std::string ProfilePasswordSalt;

    public:
    void setProfileName(); //Set the profile name
    void setProfileEmail(); //Set the Main E-Mail for the profile
    void setProfilePhoneNumber(); //Set the Main Phone Number for the Profile
    void generateProfilePWSD(); //Set the Password for your Account
    void hashProfilePWSD();
};

#endif
#ifndef startingLogicArchitecture_H
#define startingLogicArchitecture_H

//Define the main mechanism for the starting and core logic

class startingLogic {
    public:

    //Global variables
    bool validChoice = false;
    bool startSoftware = false;
    
    void coreLogic(); //The whole software logic
    void startProgrammValidation(); //Choose if the user wants to start the programm
    void mainRunningLogic(); // Defines the main logic for the runn progress
    void displayHelloMsg(); //Dipslays the Hello Message if the user starts the programm
    void displayGoodByeMsg(); //Displays the good bye Message

};

#endif
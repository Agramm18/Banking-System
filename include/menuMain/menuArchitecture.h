#ifndef MainMenue_H
#define MainMenue_H

class MainMenue {
    public:

    //Global class variables
    bool isChoiceValid = true; //For menu switch
    int menuChoice = 0;
    
    void showMenu(); //Display the menu
    void getMenuChoice(); //Get the menu choice from user
    void validateMenuChoice(); //Validate the user choice with switch()

};

#endif
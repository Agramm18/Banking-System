#ifndef MainMenue_H
#define MainMenue_H

class MainMenue {
    public:

    bool isChoiceValid = true; //For menu switch
    int menuChoice = 0;
    
    void showMenu();
    void getMenuChoice();
    void validateMenuChoice();

};

#endif
#ifndef MENU_LOGIC_H
#define MENU_LOGIC_H

#include <string>
#include <iostream>

//Display the Menu, Validate Menu Choice

class MainMenuLogic {
    //Define the main menu

    public:
    int menuChoice;

    public:

    void displayProgrammMenu(); //Show menu Options
    void collectMenuChoice(); // get the user choice
    void validateMenuChoice(); // Validate the user choice via switch

};

#endif
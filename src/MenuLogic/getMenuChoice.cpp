#include "../include/menuMain/menuArchitecture.h"
#include <iostream>

using namespace std;

void MainMenue::getMenuChoice() {
    try {
        string input;

        cout << "\nPlease choose a option from the menu [1-13]: ";
        getline (cin, input);

        if (input.empty()) {
            isChoiceValid = false;
            throw runtime_error("The field for the menu option can't be empty please enter a number between 1 and 13 to continue: ");
        }

        int userChoice = stoi(input);

        if (userChoice < 1 || userChoice > 13) {
            isChoiceValid = false;
            throw runtime_error("Invalid menu choice you can only choose options between 1 and 13 any other values will cause errors");
        }

        menuChoice = userChoice;
        isChoiceValid = true;

        cout <<"\nThe user have choosen field " << menuChoice <<endl;

    } catch (const exception& e) {
        isChoiceValid = false;
        cout <<"\nThere is an error in the Menu Choice"<<endl;
        cout <<"The error is: " << e.what() <<endl;
    }
}
#include "../include/menuMain/menuArchitecture.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main() {

    MainMenue validateMenue;
    
    cout <<"\n --------Welcome to my Banking Software-------- \n" <<endl;

    //Starting Menu
        bool validChoice = false;
        bool startSoftware = false;

        while (!validChoice) {

            try {
                string startingValue;

                cout <<"Do you want to start my programm? yes[y], no[n]: ";
                getline(cin, startingValue);

                //Main error Handeling
                if (startingValue.empty()) {
                    throw runtime_error("The Starting Value can't be empty please type in y or n to continue");

                } else if (startingValue != "y" && startingValue != "n") {
                    throw runtime_error("Invalid input detected you only can type in y or n or otherwise the programm will not work");
                }

                //Handel valid choices
                if (startingValue == "y") {
                    startSoftware = true;
                }

                else if (startingValue == "n") {
                    startSoftware = false;

                }

                validChoice = true; //Exit start loop

            } catch (runtime_error &e) {
                    cout << "\nThere is an error somewhere" <<endl;
                    cout << "The error is: " << e.what() <<"\n" <<endl;
        }
    }

    //Main Programm/Software

    if (startSoftware) {

        // Starting output when the program begins
        cout << "\n";
        cout << "****************************************************\n";
        cout << "*                                                  *\n";
        cout << "*               WELCOME TO AGRAMM BANK             *\n";
        cout << "*                                                  *\n";
        cout << "****************************************************\n\n";

        cout << "A C++ training project simulating a banking system.\n";
        cout << "This program was developed to practice basic C++ syntax,\n";
        cout << "and to learn how classes, methods, and OOP work in C++.\n";
        cout << "Learn. Practice. Build. Try Out & Enjoy!!.\n\n";

        MainMenue validateMenu; //Crate menu class as object

        bool running = true;

        //Start the Actuall programm
        while (running) {
            try {
                //Show menu
                validateMenu.showMenu();

                //Validate menu Choice
                validateMenu.getMenuChoice();

                //Switch through menu to get the right choice
                validateMenu.validateMenuChoice();

                //Quit programm if choice is 13
                if (validateMenu.menuChoice == 13) {
                    cout << "\n";
                    cout << "****************************************************\n";
                    cout << "*                                                  *\n";
                    cout << "*              THANK YOU FOR USING                 *\n";
                    cout << "*                 AGRAMM BANK                      *\n";
                    cout << "*                                                  *\n";
                    cout << "****************************************************\n\n";

                    cout << "We hope you enjoyed testing this C++ banking system.\n";
                    cout << "Thank you for exploring classes, OOP and structured logic.\n";
                    cout << "Keep learning, keep building — and see you next time!\n\n";

                    cout << "Program terminated successfully.\n";
                    cout << "Goodbye!\n\n";

                    running = false;

                }

            } catch (const exception &e) {
                cout <<"There is an error: " <<e.what() <<endl;
            }
        }
    }

    return 0;
}
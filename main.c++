#include <iostream>
#include <string>
#include <limits>

using namespace std;

//====Main Menu====//
class MainMenue {
    public:

    //Class Atributes
    int menuChoice = 0;
    bool isChoiceValid = true; //For menu switch

    //Display main menu from software
    void showMenu() {

    cout << "\n-------- Please select a menu option --------\n";
    
    cout <<"\n--- User Actions ---\n";
    cout << "1: Create User" << endl;
    cout << "2: Show User Information" << endl;

    cout << "\n--- Account Actions ---\n";
    cout << "3: Show Account Balance" << endl;
    cout << "4: Add Money to your Account" << endl;
    cout << "5: Withdraw Money from your Account" << endl;
    cout << "6: Transfer Money to another Account" << endl;
    cout << "7: Show Transaction History" << endl;

    cout << "\n--- Loans & Limits ---\n";
    cout << "8: Take out a Loan" << endl;
    cout << "9: Change Debit Limit" << endl;
    cout << "10: Change Overdraft Limit" << endl;

    cout << "\n--- Security & System ---\n";
    cout << "11: Change PIN" << endl;
    cout << "12: Close Account" << endl;
    cout << "13: Exit the Program" << endl;

    }

    //Get Menu Choice
    void getMenuChoice() {

        try {
            string input;

            cout << "\nPlease choose a option from the menu [1-13]: "<<endl;
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

        } catch (runtime_error &e) {
            isChoiceValid = false;
            cout <<"\nThere is an error in the Menu Choice"<<endl;
            cout <<"The error is: " << e.what() <<endl;
        }
    }

    void validateMenuChoice() {

    if (!isChoiceValid) {
        cout <<"The option selection can never reached because the input is invalid" <<endl;
        return;
    }

    //Validate choice with switch
    switch (menuChoice) {

        case 1:
            cout << "You can now create a new User/Bank Account" << endl;
            break;

        case 2:
            cout << "Showing user information..." << endl;
            break;

        case 3:
            cout << "Displaying your account balance..." << endl;
            break;

        case 4:
            cout << "You can now add money to your bank account." << endl;
            break;

        case 5:
            cout << "You can now withdraw money from your bank account." << endl;
            break;

        case 6:
            cout << "You can now transfer money to another account." << endl;
            break;

        case 7:
            cout << "Showing your transaction history..." << endl;
            break;

        case 8:
            cout << "You can now take out a loan." << endl;
            break;

        case 9:
            cout << "You can now change your debit limit." << endl;
            break;

        case 10:
            cout << "You can now change your overdraft limit." << endl;
            break;

        case 11:
            cout << "You can now change your PIN." << endl;
            break;

        case 12:
            cout << "You can now close your bank account." << endl;
            break;

        case 13:
            cout << "Exiting the program..." << endl;
            break;

        default:
            cout << "Unknown menu option." << endl;
            break;
    }
    }
};

int main() {
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

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
        cout << "Learn. Practice. Build. Enjoy.\n\n";

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

            } catch (const exception &e) {
                cout <<"There is an error: " <<e.what() <<endl;
            }
        } 
    }

    return 0;
}
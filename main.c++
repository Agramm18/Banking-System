#include <iostream>
#include <string>

using namespace std;

//====Define starting ammount as class====
class MoneyAmmount {
    public:
    double moneyAmmount;

    MoneyAmmount(int ammount) : moneyAmmount(ammount) {}
};


//====Main Menu====//
class MainMenue {
    public:

    int menuChoice = 0;

    //Display main menu from software
    void showMenu() {

    cout << "\n-------- Please select a menu option --------\n";

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

            cout << "Please choose a option from the menu [1-13]: ";
            getline (cin, input);

            int userChoice = stoi(input);

            if (userChoice < 1 || userChoice > 13) {
                throw runtime_error("Invalid menu choice you can only choose options between 1 and 13 any other values will cause errors");
            }

            menuChoice = userChoice; 

        } catch (runtime_error &e) {
            cout <<"\nThere is an error in the Menu Choice"<<endl;
            cout <<"The error is: " << e.what() <<endl;
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
        //Starting output if you are in the programm
        cout <<"\n--------You are now in the main Programm-----------\n"<<endl;
        cout <<"This Programm simulates a Banking System--------------";
        cout <<"Have fun while using it i developed this programm to learn basic c++ syntax and ruels\n";

        MainMenue validateMenu; //Crate menu class as object

        bool running = true;

        //Start the Actuall programm
        while (running) {
            try {
                //Show menu
                validateMenu.showMenu();

                //Validate menu Choice
                validateMenu.getMenuChoice();
            } catch (const exception &e) {
                cout <<"There is an error: " <<e.what() <<endl;
            }
        } 
    }

    return 0;
}
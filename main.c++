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
    int MenueChoice;

    MainMenue(int menuChoice) : MenueChoice(menuChoice) {}

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
};

//====Menu Functions===//

MainMenue createUser() {
    string user;
    int userAge;
    string bankingCard;
    string IBAN;
    string BIC;
    int BankingPIN;
    int expirationDate;


}

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
        bool running = true;

        //Start the Actuall programm
        while (running) {
            try {

            }
        }
    }

    return 0;
}
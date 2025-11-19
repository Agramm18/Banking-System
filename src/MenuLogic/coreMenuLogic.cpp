#include "../include/menuMain/menuArchitecture.h"
#include <iostream>

using namespace std;

//Display Menu Options
void MainMenue::showMenu () {
    
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

//Let the user choose a option
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

//Validate the option
void MainMenue::validateMenuChoice() {
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
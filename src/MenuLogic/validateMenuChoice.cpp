#include "../include/menuMain/menuArchitecture.h"
#include <iostream>

using namespace std;

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
#include "menuMain/menuArchitecture.h"
#include "programmFunctionsMain/userActionsMain.h"
#include <iostream>
#include <string>

using namespace std;

//Display Menu Options
void MainMenue::showMenu () {
    
    cout << "\n================= BANKING SYSTEM MENU =================\n";

    cout << "\n--- User Actions --------------------------------------\n";
    cout << " 1. Create User\n";
    cout << " 2. Select Bankcard Type\n";

    cout << "\n--- Account Actions -----------------------------------\n";
    cout << " 3. Add Money\n";
    cout << " 4. Withdraw Money\n";
    cout << " 5. Transfer Money\n";
    cout << " 6. Add Standing Order\n";

    cout << "\n--- Loans & Limits ------------------------------------\n";
    cout << " 7. Take out a Loan\n";
    cout << " 8. Change Debit Limit\n";
    cout << " 9. Change Overdraft Limit\n";

    cout << "\n--- Security & System ---------------------------------\n";
    cout << "10. Change PIN\n";
    cout << "11. Block Card\n";

    cout << "\n--- Display Information -------------------------------\n";
    cout << "12. Display Account Details\n";
    cout << "13. Display Security Information\n";
    cout << "14. Display Account Balance\n";
    cout << "15. Display Transfer Actions\n";
    cout << "16. Display Standing Orders\n";
    cout << "17. Display Outstanding Payments\n";
    cout << "18. Display Your Cards\n";

    cout << "\n--- Other ----------------------------------------------\n";
    cout << "19. Exit Program\n";

    cout << "\n========================================================\n";

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
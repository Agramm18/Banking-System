//Include imports to use other files
#include "menuMain/menuArchitecture.h"
#include "startingLogicMain/startingLogicArchitecture.h"
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

        cout << "\nPlease choose a option from the menu [1-19]: ";
        getline (cin, input);

        if (input.empty()) {
            isChoiceValid = false;
            throw runtime_error("The field for the menu option can't be empty please enter a number between 1 and 13 to continue: ");
        }

        int userChoice = stoi(input);

        if (userChoice < 1 || userChoice > 19) {
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

    UserLogic userActions;
    MainMenue menuActions;
    startingLogic startingActions;

    if (!isChoiceValid) {
        cout <<"The option selection can never reached because the input is invalid" <<endl;
        return;
    }

     //Validate choice with switch
    switch (menuChoice) {

        // --- User Actions ---
        case 1:
            cout << "You can now create a new user / bank account..." << endl;
            break;

        case 2:
            cout << "You can now select a bankcard type..." << endl;
            break;

        // --- Account Actions ---
        case 3:
            cout << "You can now add money to your account..." << endl;
            break;

        case 4:
            cout << "You can now withdraw money from your account..." << endl;
            break;

        case 5:
            cout << "You can now transfer money to another account..." << endl;
            break;

        case 6:
            cout << "You can now add a standing order..." << endl;
            break;

        // --- Loans & Limits ---
        case 7:
            cout << "You can now take out a loan..." << endl;
            break;

        case 8:
            cout << "You can now change your debit limit..." << endl;
            break;

        case 9:
            cout << "You can now change your overdraft limit..." << endl;
            break;

        // --- Security & System ---
        case 10:
            cout << "You can now change your PIN..." << endl;
            break;

        case 11:
            cout << "You can now block your card..." << endl;
            break;

        // --- Display Information ---
        case 12:
            cout << "Displaying your account details..." << endl;
            break;

        case 13:
            cout << "Displaying your security information..." << endl;
            break;

        case 14:
            cout << "Displaying your account balance..." << endl;
            break;

        case 15:
            cout << "Displaying your transfer actions..." << endl;
            break;

        case 16:
            cout << "Displaying your standing orders..." << endl;
            break;

        case 17:
            cout << "Displaying outstanding payments..." << endl;
            break;

        case 18:
            cout << "Displaying your registered cards..." << endl;
            break;

        // --- Program Exit ---
        case 19:
            cout << "Exiting the program..." << endl;
            startingActions.displayGoodByeMsg();
            break;

        // --- Default ---
        default:
            cout << "Unknown menu option. Please select a valid number." << endl;
            break;
    }

}
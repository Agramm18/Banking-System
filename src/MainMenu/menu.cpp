#include <MenuLogic/menuLogic.h>
#include <iostream>
#include <string>
#include <limits>

using namespace std;

void MainMenuLogic::displayProgrammMenu() {

    cout << "==================== MAIN MENU ====================\n\n";

    cout << "----- Profile & Accounts -----\n";
    cout << " 1. Create Profile\n";
    cout << " 2. Create Bank Account\n";
    cout << " 3. Edit Account Details\n";
    cout << " 4. Create a New Card\n\n";

    cout << "----- Banking Overview -----\n";
    cout << " 5. Show General Balance\n";
    cout << " 6. View All Transactions\n";
    cout << " 7. Show Pending Transactions\n\n";

    cout << "----- Limits & Permissions -----\n";
    cout << " 8. Adjust General Card Limit\n";
    cout << " 9. Adjust Credit Card Limit\n";
    cout << "10. Adjust Overdraft Limit\n\n";

    cout << "----- Standing Orders -----\n";
    cout << "11. Create Standing Order\n";
    cout << "12. Edit Standing Orders\n";
    cout << "13. Delete Standing Orders\n\n";

    cout << "----- Banking Actions -----\n";
    cout << "14. Deposit Money\n";
    cout << "15. Withdraw Money\n";
    cout << "16. Transfer Money\n\n";

    cout << "----- Security -----\n";
    cout << "17. Close Account\n";
    cout << "18. Close Card\n";
    cout << "19. Change PIN\n";
    cout << "20. Add Power of Attorney\n";
    cout << "21. Enable 2FA Authentication\n";
    cout << "22. Disable 2FA Authentication\n\n";

    cout << "---------------------------------------------------\n";
    cout << "23. Quit Program\n";
    cout << "===================================================\n";
}

void MainMenuLogic::collectMenuChoice() {

    string userInput;
    int userMenuChoice;

    while (true) {
        try {
            cout <<"Please Choose a option from the main menu: ";
            getline(cin, userInput);

            //Error handeling
            if (userInput.empty()) {
                throw runtime_error("Please choose a menu option");
            } else {
                userMenuChoice = stoi(userInput);

                if (userMenuChoice < 1 || userMenuChoice > 23) {
                    throw runtime_error("The Menu is out of range [1-23]");
                } else {
                    menuChoice = userMenuChoice;
                    break;
                }
            } 

        } catch(runtime_error &e) {
            cout <<"There is an error";
            cout <<e.what();
        }
    }
}
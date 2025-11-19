#include "../include/menuMain/menuArchitecture.h"
#include <iostream>

using namespace std;

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
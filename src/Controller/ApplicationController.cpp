#include <ProgrammController/controller.h>
#include <MenuLogic/menuLogic.h>
#include <iostream>
#include <string>

using namespace std;

void ApplicationController::displayHelloMSG() {
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
}

void ApplicationController::run() {

    displayHelloMSG();

    MainMenuLogic mainMenu;
    mainMenu.displayProgrammMenu();
    mainMenu.collectMenuChoice();
}
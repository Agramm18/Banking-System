#ifndef MainLogic_H
#define MainLogic_H

//Define Main Programm Logic for the int main()

class MainLogic {
    public:

    //Global class variables
    bool validChoice = false;
    bool startSoftware = false;
    
    void StartingLogic(); //Define Starting Logic
    void MainPorgrammLogic(); //Define Main Logic
    void QuitLogic(); //Define Quitting Logic
};

#endif
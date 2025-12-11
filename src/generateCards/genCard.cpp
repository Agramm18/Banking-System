#include <userData/account/accountData.h>
#include <BankCards/generator.h>

#include <iostream>
#include <random>
#include <unordered_set>

using namespace std;

void generationValues::generateBIC() {
    //Set the name Values for the Bank

    cout <<"The Card BIC will be set now" <<endl;

    string BIC;

    try {
        //Generate Bank Code

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> upperDist(1, 9);
        unordered_set<int> upperSet;

        while (upperSet.size() < 4) {
            int num = upperDist(gen);
            upperSet.insert(num);
        }

        cout <<"The generated Bank Code is: ";
        for (int n : upperSet) {
            char letter = 'A' + n;
            cout << letter << " ";
        }

        cout <<endl;
    } catch (runtime_error &e) {
        cout <<"The error is: " <<e.what() <<endl;
    }
}
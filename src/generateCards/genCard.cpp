#include <userData/account/accountData.h>
#include <BankCards/generator.h>

#include <iostream>
#include <random>
#include <unordered_set>

using namespace std;


//Convert the sets to strings
string setToString(const unordered_set<int>& s) {
    string result;
    for (int n : s) {
        result += char('A' + n);
    }
    return result;
}


void generationValues::generateBIC() {
    //Set the name Values for the Bank

    cout <<"The Card BIC will be set now" <<endl;

    string BIC;

    try {
        //Generate Bank Code

        random_device rd;
        mt19937 gen(rd());

        uniform_int_distribution<> upperDist(0, 25);
        unordered_set<int> SetBankCode;

        while (SetBankCode.size() < 4) {
            int num = upperDist(gen);
            SetBankCode.insert(num);
        }

        cout <<"The generated Bank Code is: ";
        for (int n : SetBankCode) {
            char letter = 'A' + n;
            cout << letter << " ";
        }

        cout <<endl;


        //Collect Country code

        account data;
        string countryCode = data.getCountryCode().countryCode; //Collect the country code from getter

        //Generate random location code
        unordered_set<int> SetLocationCode;

        while (SetLocationCode.size() < 2) {
            int num = upperDist(gen);
            SetLocationCode.insert(num);
        }

        cout <<"The generated location code is: ";
        for (int n : SetLocationCode) {
            char letter = 'A' + n;
            cout << letter << " ";
        }

        cout << endl;


        //Generate branch code
        unordered_set<int> SetBranchCode;

        while (SetBranchCode.size() < 3) {
            int num = upperDist(gen);
            SetBranchCode.insert(num);
        }

        cout <<"The generated Branchcode is: ";
        for (int n : SetBranchCode) {
            char letter = 'A' + n;
            cout << letter << " ";
        }

        cout << endl;

        //Convert the Sets To a String

        string bankCode = setToString(SetBankCode);

        string locationCode = setToString(SetLocationCode);
        string branchCode = setToString(SetBranchCode);

        string generatedBic = bankCode + countryCode + locationCode + branchCode;

        cout <<"The generated BIC is: " <<generatedBic <<endl;

    } catch (runtime_error &e) {
        cout <<"The error is: " <<e.what() <<endl;
    }
}
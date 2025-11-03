/* 
 * File:   main.cpp
 * Author: Matthew Madrigal
 * Created on October 31st, 2025, 7:01 pm,
 * Purpose:  To display a customer's account infornmation and properly execute commands
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
#include "customer.h"

//Global Constants - Math/Science/Conversions only

//Function Prototypes
bool valMoney(string, bool);
bool valNum(string);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    const int ACNUM = 5;    // Max length for an account number
    Customer *user = new Customer;
    string input = "";
    double sBal, fBal;
    bool valid; // This variable will be used every time the program takes in user input
    //Initialize Variables

    // Gets the account number.
    do {
        valid = true;
        cout << "Enter an account number (Must be 5 digits): ";
        cin >> input;
        if(input.length() == ACNUM) {
            for(int i = 0; i < ACNUM; i++) {
                if(!isdigit(input[i])) valid = false;
            }
        } else valid = false;
        if(!valid) cout << "Invalid account number entered." << endl;
    } while(!valid);
    cin.ignore();
    // Moves validated input to structure
    strncpy(user->accnum, input.c_str(), 5);
    user->accnum[ACNUM] = '\0';     // Caps off cstring with a null terminator
    input.clear();

    do {
        cout << "Enter a name: ";
        getline(cin, input);
        if(input.empty()) cout << "Name can not be empty" << endl;
    } while(input.empty());
    user->name = input;
    input.clear();

    do {
        cout << "Enter an address: ";
        getline(cin, input);
        if(input.empty()) cout << "Address can not be empty" << endl;
    } while(input.empty());
    user->addr = input;

    // Gets the starting balance. I don't think you can open an account with negative balance so only positive is allowed
    do {
        cout << "Enter the starting balance: $";
        cin >> input;
        valid = valMoney(input, true);  // Verifies the inputed number is valid (allows negative)
        
        if(!valid) cout << "Invalid balance entered." << endl;
    } while(!valid);
    // Moves validated input to structure
    user->bal = stod(input);
    input.clear();
    
    // Gets the number of checks to create. This has to be positive
    do {
        cout << "Enter the number of checks to create: ";
        cin >> input;
        valid = valNum(input);
        if(!valid) cout << "Invalid amount entered." << endl;
    } while(!valid);
    user->drSize = stoi(input);
    input.clear();

    // Creates array of checks and gets the amount withdrawn from the user.
    user->draw = new double[user->drSize];

    for(int drInd = 0; drInd < user->drSize; drInd++) {
        do {
            valid = true;
            cout << "Enter an amount for a check: $";
            cin >> input;
            valid = valMoney(input, false); // Verifies the inputed number is valid (only positive)
            if(!valid) cout << "Invalid amount entered." << endl;
        } while(!valid);
        user->draw[drInd] = stod(input);
        input.clear();
    }

    // Gets the number of deposits to create. This has to be positive
    do {
        cout << "Enter the number of deposits to create: ";
        cin >> input;
        valid = valNum(input);
        if(!valid) cout << "Invalid amount entered." << endl;
    } while(!valid);
    user->deSize = stoi(input);
    input.clear();

    // Creates array of checks and gets the amount withdrawn from the user.
    user->deposit = new double[user->deSize];

    for(int deInd = 0; deInd < user->deSize; deInd++) {
        do {
            cout << "Enter an amount for a deposit: $";
            cin >> input;
            valid = valMoney(input, false); // Verifies the inputed number is valid (only positive)
            if(!valid) {
                cout << "Invalid amount entered." << endl;
            }
        } while(!valid);
        user->deposit[deInd] = stod(input);
    }
    
    //The Process -> Map Inputs to Outputs

    sBal = user->bal;

    // Subtracts the checks from the balance
    for(int i = 0; i < user->drSize; i++) sBal -= user->draw[i];

    // Adds the deposits to the balance
    for(int i = 0; i < user->deSize; i++) sBal += user->deposit[i];

    // Adds any neccesary fees
    fBal = sBal;
    if(fBal < 0) fBal -= 20.0;
    
    //Display Inputs/Outputs
    cout << "The following data has been entered." << endl;
    cout << "Account number: " << user->accnum << endl;
    cout << "Name: " << user->name << endl;
    cout << "Starting balance: $" << fixed << setprecision(2) << user->bal << endl;
    cout << "Number of checks written: " << user->drSize << endl;
    cout << "Check amounts written: ";
    for(int i = 0; i < user->drSize; i++) cout << "$" << fixed << setprecision(2) << user->draw[i] << " ";
    cout << endl;
    cout << "Number of deposits: " << user->deSize << endl;
    cout << "Deposits: ";
    for(int i = 0; i < user->deSize; i++) cout << "$" << fixed << setprecision(2) << user->deposit[i] << " ";
    cout << endl;
    cout << "Balance after checks and deposits: $" << fixed << setprecision(2) << sBal << endl;
    if(sBal != fBal) cout << "Since your account has been overdrawn, an addition $20 fee has been applied" << endl;
    else cout << "No addition fees were applied to your account" << endl;
    cout << "Final balance after fees: $" << fixed << setprecision(2) << fBal << endl;

    //Exit the Program
    delete []user->draw;
    delete []user->deposit;
    delete user;
    return 0;
}

bool valMoney(string input, bool neg) {
    bool deci = false, isZero = true;
    int decLen = 0;
    if(input.length() == 0) return false;
    for(int i = 0; i < input.length(); i++) {
        if(!isdigit(input[i])) {
            if(input[i] == '.') {
                if(deci) return false;
                deci = true;
            } else {
                if(!neg || i!=0 || input[i] != '-') return false;
                if(i+1 < input.length()) {
                    if(!isdigit(input[i+1])) return false;
                } else return false;
            }
        } else {
            if(input[i] != '0') isZero = false;
            if(deci) {
                decLen++;
                if(decLen > 2) return false;
            }
        }
    }
    return !isZero;
}

bool valNum(string input) {
    bool isZero = true;
    if(input.length() > 0) {
        for(int i = 0; i < input.length(); i++) {
            if(!isdigit(input[i])) return false;
            if(input[i] != '0') isZero = false;
        }
    } else return false;
    return !isZero;
}
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
bool valMoney(string, bool, bool);
bool valNum(string, bool);
bool valUsedStr(string);

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

    // Gets the name. Presumably we don't want a blank name. Verfies its not blank
    do {
        cout << "Enter a name: ";
        getline(cin, input);
        valid = valUsedStr(input);
        if(!valid) cout << "Name can not be empty" << endl;
    } while(!valid);
    user->name = input;
    input.clear();

    // Gets the address. Presumably we don't want a blank address. Verifies its not blank
    do {
        cout << "Enter an address: ";
        getline(cin, input);
        valid = valUsedStr(input);
        if(!valid) cout << "Address can not be empty" << endl;
    } while(!valid);
    user->addr = input;

    // Gets the starting balance. Just in case, I allowed negative balances. Not allowing it would just require setting the bool to false in valMoney parameter 2
    do {
        cout << "Enter the starting balance: $";
        cin >> input;
        valid = valMoney(input, true, true);  // Verifies the inputed number is valid (allows negative and zero)
        if(!valid) cout << "Invalid balance entered." << endl;
    } while(!valid);
    // Moves validated input to structure
    user->bal = stod(input);
    input.clear();
    
    // Gets the number of checks to create. This has to be positive
    do {
        cout << "Enter the number of checks to create: ";
        cin >> input;
        valid = valNum(input, false);   // No zero
        if(!valid) cout << "Invalid amount entered." << endl;
    } while(!valid);
    user->drSize = stoi(input);
    input.clear();

    // Creates array of checks
    user->draw = new double[user->drSize];

    // Gets the withdrawn amount with each check. Has to be positive
    for(int drInd = 0; drInd < user->drSize; drInd++) {
        do {
            valid = true;
            cout << "Enter an amount for a check: $";
            cin >> input;
            valid = valMoney(input, false, false); // Verifies the inputed number is valid (only positive. no zero)
            if(!valid) cout << "Invalid amount entered." << endl;
        } while(!valid);
        user->draw[drInd] = stod(input);
        input.clear();
    }

    // Gets the number of deposits to create. This has to be positive
    do {
        cout << "Enter the number of deposits to create: ";
        cin >> input;
        valid = valNum(input, false);   // No zero
        if(!valid) cout << "Invalid amount entered." << endl;
    } while(!valid);
    user->deSize = stoi(input);
    input.clear();

    // Creates array of deposits
    user->deposit = new double[user->deSize];

    // Gets the amount withdrawn from the user. Has to be positive
    for(int deInd = 0; deInd < user->deSize; deInd++) {
        do {
            cout << "Enter an amount for a deposit: $";
            cin >> input;
            valid = valMoney(input, false, false); // Verifies the inputed number is valid (only positive. no zero)
            if(!valid) {
                cout << "Invalid amount entered." << endl;
            }
        } while(!valid);
        user->deposit[deInd] = stod(input);
    }
    
    //The Process -> Map Inputs to Outputs
    // Gets the starting balance
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
    // Prints all the checks
    for(int i = 0; i < user->drSize; i++) cout << "$" << fixed << setprecision(2) << user->draw[i] << " ";
    cout << endl;
    cout << "Number of deposits: " << user->deSize << endl;
    cout << "Deposits: ";
    // Prints all the deposits
    for(int i = 0; i < user->deSize; i++) cout << "$" << fixed << setprecision(2) << user->deposit[i] << " ";
    cout << endl;
    cout << "Balance after checks and deposits: $" << fixed << setprecision(2) << sBal << endl;
    // Checks if a fee is applied and prints it
    if(sBal != fBal) cout << "Since your account has been overdrawn, an addition $20 fee has been applied" << endl;
    else cout << "No addition fees were applied to your account" << endl;
    cout << "Final balance after fees: $" << fixed << setprecision(2) << fBal << endl;

    //Exit the Program
    delete []user->draw;
    delete []user->deposit;
    delete user;
    return 0;
}

// Makes sure the user only inputs a valid currency amount (y.xx)
// There can be infinite amount of y, only 2 x because cents only can go down to 2 decimals (unless you consider half cents which lasted less than 100 years)
bool valMoney(string input, bool neg, bool zero) {
    bool deci = false, isZero = true;
    int decLen = 0;
    if(input.length() == 0) return false;
    for(int i = 0; i < input.length(); i++) {
        if(!isdigit(input[i])) { 
            if(input[i] == '.') {
                if(deci) return false;  // There can only be one decimal place
                deci = true;
            } else {
                if(!neg || i!=0 || input[i] != '-') return false;   // If negatives are not allowed, the - is not at the beggining, or the character we are looking at isnt - ,its invalid.
                if(i+1 < input.length()) {
                    if(!isdigit(input[i+1])) return false;  // We only get here if we are dealing with a negative or a decimal. Makes sure the next char is a digit or else it would be invalid. No "-." allowed
                } else return false;    // We can't accept just a "-" or "." (no numbers or value)
            }
        } else {
            if(input[i] != '0') isZero = false; // Keeps track of if we are dealing with a 0 value number
            if(deci) {      // Keeps track of the number of digits after the .
                decLen++;
                if(decLen > 2) return false;    // No more than 2
            }
        }
    }
    return !isZero || zero;
}

// Makes sure the user only inputs a valid nonegative int
// Since I use this function in another question, it can allow zero. Its not used here though
bool valNum(string input, bool zero) {
    bool isZero = true;
    if(input.length() > 0) {
        for(int i = 0; i < input.length(); i++) {
            if(!isdigit(input[i])) return false;    // Makes sure its all digits (no decimal)
            if(input[i] != '0') isZero = false;     // Keeps track of if its zero
        }
    } else return false;    // Can't be empty
    return !isZero || zero;
}

// Makes sure the string actually has something in it. No spaces or tabs.
bool valUsedStr(string input) {
    bool valid = false;
    for(int i = 0; i < input.length(); i++) {
        if(isprint(input[i]) && !isspace(input[i])) valid = true;
    }
    return valid;
}
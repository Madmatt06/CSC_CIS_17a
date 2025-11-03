/* 
 * File:   main.cpp
 * Author: Matthew Madrigal
 * Created on November 1st, 2025, 5:09 pm,
 * Purpose:  To get the hours someone works and print a paycheck to them.
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//User Libraries
#include "employee.h"

//Global Constants - Math/Science/Conversions only

//Function Prototypes
double calcPay(double, double);
bool valNum(string, bool);
bool valDouble(string, bool, bool);
bool valMoney(string input, bool, bool);
string digitToString(int, bool);
string teenDigString(int);
string numToPrefix(int);
string segmentPlace(int);
string numToString(int);
string segmentToString(int);
bool valUsedStr(string);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    string cmpnm;       // Company name
    string addr;        // Company Address
    Employee *emps;     // Employees
    bool run;
    bool val;           // Used to make sure input is valid

    //Initialize Variables
    do {
        cout << "Enter a company name: ";
        getline(cin, cmpnm);
        val = valUsedStr(cmpnm);
        if (!val) cout << "The company name can not be blank." << endl;
    } while(!val);

    do {
        cout << "Enter a company address: ";
        getline(cin, addr);
        val = valUsedStr(addr);
        if (!val) cout << "The company address can not be blank." << endl;
    } while(!val);

    run = true;
    while(run) {
        int size;
        string input;
        bool valid;
        do {
            cout << "Enter the number of employees: ";
            cin >> input;
            valid = valNum(input, false);
            if(!valid) cout << "Invalid number of employees entered." << endl;
        } while(!valid);
        size = stoi(input);
        emps = new Employee[size];
        cin.ignore();
        
        for(int i = 0; i < size; i++) {
            do {
                cout << "Enter the employee's name: ";
                getline(cin, emps[i].name);
                valid = valUsedStr(emps[i].name);
                if(!valid) {
                    cout << "The employee's name can not be blank." << endl;
                }
            }while(!valid);

            cout << "Enter the number of hours the employee has worked: ";
            cin >> input;
            valid = valDouble(input, false, true);
            if(!valid) {
                cout << "Invalid number of hours. Exiting program" << endl;
                run = false;
                delete []emps;
                break;
            }
            emps[i].hours = stod(input);

            cout << "Enter the payrate for the employee per hour: $";
            cin >> input;
            valid = valMoney(input, false, true);
            if(!valid) {
                cout << "Invalid payrate. Exiting program" << endl;
                run = false;
                delete []emps;
                break;
            }
            emps[i].rate = stod(input);
            cin.ignore();
        }
        if(!run) break;

        //The Process -> Map Inputs to Outputs
        for(int i = 0; i < size; i++) {
            emps[i].amount = calcPay(emps[i].hours, emps[i].rate);
        }

        //Display Inputs/Outputs
        for(int i = 0; i < size; i++) {
            cout << endl;
            // Header for paycheck
            cout << cmpnm << endl << addr << endl;
            // Actually changing part
            cout << "Name: " << setw(20) << left << emps[i].name << " Amount: $" << fixed << setprecision(2) << emps[i].amount << endl;
            cout << "Amount: " << numToString(emps[i].amount) << " dollars and " << numToString(static_cast<int>(round(emps[i].amount*100))%100) << " cents" << endl; // TODO: Add code to translate to english.
            cout << "Signature Line: _________________________________" << endl;
        }
        delete []emps;
    }
    
    //Exit the Program
    return 0;
}

double calcPay(double hours, const double rate) {
    const double dblTm = 40; // Double time threshold in hours
    const double trpTm = 50; // Triple time threshold in hours
    double amount = 0;
    double rem = hours - trpTm; // Remaining time after threshold
    if(rem > 0) {
        amount += rem*(rate*3);
        hours -= rem;
    }
    rem = hours-dblTm;
    if(rem > 0) {
        amount += rem*(rate*2);
        hours -= rem;
    }
    amount += hours*rate;
    return amount;
}

// Makes sure the user only inputs a valid nonegative int
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

// This is a reduced version of the valMoney function. Doesn't care for the number of digits after decimal
// Just makes sure its a valid double/float
bool valDouble(string input, bool neg, bool zero) {
    bool deci = false, isZero = true;
    if(input.length() == 0) return false;
    for(int i = 0; i < input.length(); i++) {
        if(!isdigit(input[i])) {
            if(input[i] == '.') {
                if(deci) return false;  // There can only be one decimal place
                deci = true;
            } else {
                if(!neg || i!=0 || input[i] != '-') return false;   // If negatives not allowed, the - is not at the beggining, or the char is not a -, its invalid
                if(i+1 < input.length()) {
                    if(!isdigit(input[i+1])) return false; // We only get here if we are dealing with a negative or a decimal. Makes sure the next char is a digit or else it would be invalid. No "-." allowed
                } else return false;    // We can't accept just a "-" or "." (no numbers or value)
            }
        } else {
            if(input[i] != '0') isZero = false; // Keeps track of it we are dealing with a 0 value number
        }
    }
    return !isZero || zero;
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
                if(!neg || i!=0 || input[i] != '-') return false;   // If negatives are not allowed, the - is not at the beggining, or the character we are looking at isnt -, its invalid.
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

// Splits the nubmer up into segments of three digits and adds the appropriate place (thousand, million, billion)
string numToString(int num) {
    if(num == 0) return "zero"; // There is nothing... Its just zero...
    string trans, add;
    int i = 0;      // Keeps track of which segment we are on, used for thousands, millions...
    while(num > 0) {
        add = segmentToString(num%1000);    // Gets translation for a segment
        if(i == 0) {     // Used to start up the proccess
            trans = add;
        } else {
            trans = add + " " + segmentPlace(i) + (trans.empty()? "" : " ") + trans;    // Adds the next translation with the correct place (million, billion...) and space if needed.
        }
        num /= 1000;    // Gets rid of digits we finished with
        i++;
    }
    return trans;
}

// Translate a segment (3 digits) into words
string segmentToString(int num) {
    string trans;
    // Handles first digit in group which requires a hundred if its not 0
    int temp = num/100;
    if(temp > 0) {
        trans += digitToString(temp, false) + " hundred";
    }
    // Handles second and third number in group. 
    temp = num%100;
    if(temp > 9 && temp < 20) { // Handles the pattern exception for the teens
        if(!trans.empty()) trans += " ";
        trans += teenDigString(temp);
    } else {    // Handles all other non teens since they follow similar patterns.
        if(!trans.empty() && temp != 0) trans += " ";
        string seg1 = digitToString(temp/10, true);
        string seg2 = digitToString(temp%10, false);
        trans += seg1;
        if(!seg1.empty() && !seg2.empty() && seg2 != "zero") trans += " ";
        if(seg2 != "zero") trans += seg2;
    }
    return trans;

}

// Makes sure the string actually has something in it. No spaces or tabs.
bool valUsedStr(string input) {
    bool valid = false;
    for(int i = 0; i < input.length(); i++) {
        if(isprint(input[i]) && !isspace(input[i])) valid = true;
    }
    return valid;
}

// The prefixes used most of the time for the numbers.
string numToPrefix(int num) {
    switch(num) {
        case 9:
        return "nin";
        case 8:
        return "eigh";
        case 7:
        return "seven";
        case 6:
        return "six";
        case 5:
        return "fi";
        case 4:
        return "fo";
        case 3:
        return "th";
        case 2:
        return "tw";
        default:
        return "";
    }
}

// converts a single digit to words. Can handle the tens place to with it's different suffixes and slightly different spelling
string digitToString(int num, bool ten) {
    switch(num) {
        case 9:
        return numToPrefix(num) + (ten? "ty": "e");
        case 8:
        return numToPrefix(num) + (ten? "ty": "t");
        case 7:
        case 6:
        return numToPrefix(num) + (ten? "ty": "");
        case 5:
        return numToPrefix(num) + (ten? "fty": "ve");
        case 4:
        return numToPrefix(num) + (ten? "rty": "ur");
        case 3:
        return numToPrefix(num) + (ten? "irty": "ree");
        case 2:
        return numToPrefix(num) + (ten? "enty": "o");
        case 1:
        return ten? "ten" : "one";
        case 0:
        return ten? "" : "zero";
        default:
        return "";
    }
}

// Used for special teen case. Many don't follow a similar pattern to others (20s 30s etc...)
string teenDigString(int num) {
    string temp;
    switch(num) {
        case 19:
        case 17:
        case 16:
        case 14:
        return digitToString(num%10, false) + "teen";
        case 18:
        temp = "teen";
        break;
        case 15:
        temp = "fteen";
        break;
        case 13:
        temp = "irteen";
        break;
        case 12:
        return "twelve";
        case 11:
        return "eleven";
        case 10:
        return "ten";
        default:
        return "";
    }
    return numToPrefix(num%10) + temp;  // Adds the ending to the prefix for the number.
}

// A bunch of segment names for the english version. (ex: five hundred *quintillion* two hundred thirty three *billion* forty two)
string segmentPlace(int num) {
    string temp;
    switch(num) {
        case 9:
        temp = "oct";
        break;
        case 8:
        temp = "sept";
        break;
        case 7:
        temp = "sext";
        break;
        case 6:
        temp = "quint";
        break;
        case 5:
        temp = "quadr";
        break;
        case 4:
        temp = "tr";
        break;
        case 3:
        temp = "b";
        break;
        case 2:
        temp =  "m";
        break;
        case 1:
        return "thousand";  // Doesn't end in "illion"
        case 0:
        return "";
        default:    // Nothing should ever normally go this far, I hope...
        return ",";
    }
    return temp + "illion"; // Almost all of them end in "illion"
}


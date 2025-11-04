/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Purpose:  Menu using Functions,
 *           extend for midterm
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
#include "customer.h"
#include "employee.h"
#include "prime.h"
#include "primes.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm4();
void prblm5();
void prblm6();
void prblm7();
// Supporting Functions
bool valMoney(string, bool, bool);
bool valNum(string, bool);
bool valUsedStr(string);
double calcPay(double, double);
bool valDouble(string, bool, bool);
string digitToString(int, bool);
string teenDigString(int);
string numToPrefix(int);
string segmentPlace(int);
string numToString(int);
string segmentToString(int);
bool valMessage(string);
bool valMessMin(string);
void encrypt();
void decrypt();
bool isPrime(int);
int power(int, int&);
int nPrimes(int);
void cleanUp(Primes *);
Primes *factor(int);
void prtPrms(const Primes *);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    //Loop and Display menu
    do{
        menu();
        cin>>choice;

        //Process/Map inputs to outputs
        switch(choice){
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '3':{prblm3();break;}
            case '4':{prblm4();break;}
            case '5':{prblm5();break;}
            case '6':{prblm6();break;}
            case '7':{prblm7();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='7');
    
    //Exit stage right!
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Menu
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void menu(){
    //Display menu
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1"<<endl;
    cout<<"Type 2 for Problem 2"<<endl;
    cout<<"Type 3 for Problem 3"<<endl;  
    cout<<"Type 4 for Problem 4"<<endl;   
    cout<<"Type 5 for Problem 5"<<endl;   
    cout<<"Type 6 for Problem 6"<<endl;    
    cout<<"Type 7 for Problem 7"<<endl<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 1
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm1(){
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
    cout << "Address: " << user->addr << endl;
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
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 2
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm2(){
    //Declare Variables
    string cmpnm;       // Company name
    string addr;        // Company Address
    Employee *emps;     // Employees
    bool run;
    bool val;           // Used to make sure input is valid

    //Initialize Variables
    cin.ignore(); // This was needed to dismiss the new line from the menu. The original program does not have this
    // Gets company name (cannot be blank)
    do {
        cout << "Enter a company name: ";
        getline(cin, cmpnm);
        val = valUsedStr(cmpnm);
        if (!val) cout << "The company name can not be blank." << endl;
    } while(!val);

    //Gets company address (cannot be blank)
    do {
        cout << "Enter a company address: ";
        getline(cin, addr);
        val = valUsedStr(addr);
        if (!val) cout << "The company address can not be blank." << endl;
    } while(!val);

    // Keeps running until an invalid payrate or hours is entered
    run = true;
    while(run) {
        int size;
        string input;
        bool valid;
        // Gets the number of employees and then creates an array of the appropriate size
        do {
            cout << "Enter the number of employees: ";
            cin >> input;
            valid = valNum(input, false);
            if(!valid) cout << "Invalid number of employees entered." << endl;
        } while(!valid);
        size = stoi(input);
        emps = new Employee[size];
        cin.ignore();
        // Goes through the whole array
        for(int i = 0; i < size; i++) {
            // Gets the employee's name
            do {
                cout << "Enter the employee's name: ";
                getline(cin, emps[i].name);
                valid = valUsedStr(emps[i].name);
                if(!valid) {
                    cout << "The employee's name can not be blank." << endl;
                }
            }while(!valid);
            // Gets the employee's work time
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
            // Gets the employee's pay rate
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
        if(!run) break; // Exits the program if the user typed in an invalid payrate or hours worked

        //The Process -> Map Inputs to Outputs
        for(int i = 0; i < size; i++) {
            emps[i].amount = calcPay(emps[i].hours, emps[i].rate);
        }

        //Display Inputs/Outputs
        for(int i = 0; i < size; i++) {
            cout << endl;
            // Header for paycheck
            cout << cmpnm << endl << addr << endl;
            // Actually changing part of paycheck
            cout << "Name: " << setw(20) << left << emps[i].name << " Amount: $" << fixed << setprecision(2) << emps[i].amount << endl;
            cout << "Amount: " << numToString(emps[i].amount) << " dollars and " << numToString(static_cast<int>(round(emps[i].amount*100))%100) << " cents" << endl; // TODO: Add code to translate to english.
            cout << "Signature Line: _________________________________" << endl;
        }
        delete []emps;
    }
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 3
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm3(){
    cout<<"This solution is included in another project"<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 4
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm4(){
    //Declare Variables
    string input;
    // Initialize Variables
    cout << "Would you like to encrypt or decrypt?: ";
    cin >> input;

    //The Process -> Map Inputs to Outputs
    // Makes it all lower case.
    for(int i = 0; i < input.length(); i++) {
        input[i] = tolower(input[i]);
    }
    // Selects the correct option. If the input is invalid, exits
    if(input == "encrypt") {
        encrypt();
    } else if(input == "decrypt") {
        decrypt();
    } else {
        cout << "Invalid selection. Exiting program" << endl;
    }
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 5
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm5(){
    cout<<"char 5" << endl
    << "unsigned char 5" << endl 
    << "bool 1" << endl 
    << "short int 7" << endl
    << "unsigned short int 8" << endl
    << "int 12" << endl
    << "unsigned int 12" << endl
    << "long int 20" << endl
    << "unsigned long int 20" << endl
    << "long long int 20" << endl
    << "unsigned long long int 20" << endl
    << "float 34 (float lost precision and was wrong at 14. Float kept storing larger values up to 34. After 34 cout prints infinity)" << endl
    << "double 170 (double may have lost precision and was wrong or my calculator may have been wrong at 22. double kept storing larger values up to 170. After 170 cout prints infinity)" << endl
    << "long double 170 (long double may have lost precision and was wrong or my calculator may have been wrong at 22. long double kept storing larger values up to 170. After 170 cout prints infinity)"<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 6
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm6(){
    cout<<"Part a:" << endl
    << "49.1875 base 10 in base 16 = 31.3, base 2 = 110001.0011, base 8 = 61.16, and nasa format = 01100010011000000000000000000110" << endl
    << "3.07421675 base 10 in base 16 = 3.13, base 2 = 11.00010011, base 8 = 3.046, and nasa format = 01100010011000000000000000000010" << endl
    << "0.2 base 10 in base 16 = 0.3333 repeating, base 2 = 0.001100110011 repeating, base 8 = 0.1463 repeating, and nasa format = 01100110011001100110011011111110" << endl;
    cout << "Part b:" << endl
    << "-49.1875 base 10 in nasa format: 10011101101000000000000000000110" << endl
    << "-3.07421675 base 10 in nasa format: 10011101101000000000000000000010" << endl
    << "0.2 base 10 in nasa format: 10011001100110011001101011111110" << endl;
    cout << "Part c:" << endl
    << "69999902 nasa format to decimal = 3.299999714" << endl
    << "69999903 nasa format to decimal = 6.599999428" << endl
    << "966667FF nasa format to decimal = -0.412499964" << endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 7
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm7(){
    //Declare Variables
    unsigned short int n;
    string input;
    bool valid;
    //Initialize Variables
    // Gets a number and makes sure its valid
    do {
        cout << "Enter a number [2,65000]: ";
        cin >> input;
        valid = valNum(input, false);
        if(valid) {
            n = stoi(input);
            valid = (n >= 2 && n <= 65000);
        }
    } while(!valid);
    
    //The Process -> Map Inputs to Outputs
    // Gets primes
    Primes *primes = factor(n);
    
    //Display Inputs/Outputs
    // Displays primes
    prtPrms(primes);

    //Exit the Program
    cleanUp(primes);
}

// Supporting functions

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

// Makes sure the string actually has something in it. No spaces or tabs.
bool valUsedStr(string input) {
    bool valid = false;
    for(int i = 0; i < input.length(); i++) {
        if(isprint(input[i]) && !isspace(input[i])) valid = true;
    }
    return valid;
}

// Calculates pay given hours and rate
double calcPay(double hours, const double rate) {
    const double dblTm = 40; // Double time threshold in hours
    const double trpTm = 50; // Triple time threshold in hours
    double amount = 0;
    double rem = hours - trpTm; // Remaining time after threshold
    // Handles triple time
    if(rem > 0) {
        amount += rem*(rate*3);
        hours -= rem;
    }
    // Handles double time
    rem = hours-dblTm;
    if(rem > 0) {
        amount += rem*(rate*2);
        hours -= rem;
    }
    // Handles normal time
    amount += hours*rate;
    return amount;
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

void encrypt() {
    //Declare Variables
    const int SIZE = 4; // Messages are only 4 digits long
    int message[SIZE];
    string input;       // The user input that will be validated
    bool valid;         // Stores if the user input was valid or not
    
    //Initialize Variables
    // Gets the message to encrypt and validates it
    do {
        cout << "Enter your message to encrypt: ";
        cin >> input;
        valid = valMessage(input);
        if(!valid) {
            cout << "Invalid message entered." << endl;
        }
    } while(!valid);
    
    //The Process -> Map Inputs to Outputs
    for(int i = 0; i < SIZE; i++) {
        message[i] = input[i] - '0';        // Converts the digits of the message to ints
        message[i] = (message[i] + 3) % 8;  // Adds 3 and takes the modulus 8 to encrypt
    }
    // Swaps the digits
    for(int i = 0; i < SIZE/2; i++) {
        int temp = message[i];
        message[i] = message[(SIZE/2)+i];
        message[(SIZE/2)+i] = temp;
    }

    
    //Display Inputs/Outputs
    cout << endl << "Encrypted Message: ";
    for(int i = 0; i < SIZE; i++) {
        cout << message[i];
    }
    cout << endl;
}

void decrypt() {
    //Declare Variables
    const int SIZE = 4; // Only 4 digits
    int message[SIZE];
    string input;       // Stores user input to be validated
    bool valid;         // Stores if input is valid
    
    //Initialize Variables
    // Gets a message to decrypt
    do {
        cout << "Enter your message to decrypt: ";
        cin >> input;
        valid = valMessage(input);
        // If the first function returned false, check if its due to corruption during transmission or user error
        if(!valid) {
            if(!valMessMin(input)) cout << "Invalid message entered." << endl;
            else cout << "The message seems to have been corrupted during transmission due to an 8 or 9 existing in it." << endl;
        }
    } while(!valid);
    
    //The Process -> Map Inputs to Outputs
    // Converts to ints
    for(int i = 0; i < SIZE; i++) {
        message[i] = input[i] - '0';
    }

    // Swaps the places
    for(int i = 0; i < SIZE/2; i++) {
        int temp = message[i];
        message[i] = message[(SIZE/2)+i];
        message[(SIZE/2)+i] = temp;
    }

    // Performs the operations to reverse it. (If its greater than 2, subtract 3, otherwise add 5. Thats the best way I could figure out reversing modulus)
    for(int i = 0; i < SIZE; i++) {
        if(message[i] > 2) message[i] -= 3;
        else message[i] += 5;
    }

    //Display Inputs/Outputs
    cout << endl << "Decrypted Message: ";
    for(int i = 0; i < SIZE; i++) {
        cout << message[i];
    }
    cout << endl;

}

// Validates the user input is valid (multiple digits all between 0 and 7 inclusive)
bool valMessage(string input) {
    if(input.length() != 4) return false;
    for(int i = 0; i < input.length(); i++) {
        if(!isdigit(input[i]) || input[i] > '7') return false;
    }
    return true;
}

// Basically the same as the valMessage but ignoring check for 8 and 9 that way the program can check if there is an error in the transmission
bool valMessMin(string input) {
    if(input.length() != 4) return false;
    for(int i = 0; i < input.length(); i++) {
        if(!isdigit(input[i])) return false;
    }
    return true;
}

// Checks if a number is prime by dividing up to the square root (the other half doesn't matter, the first half relies on the second half.)
bool isPrime(int num) {
    if(num < 2) return false;
    int max = sqrt(num);
    for(int i = 2; i <= max; i++) {
        if(num%i == 0) return false;
    }
    return true;
}

// Gets the max power something can divide into num. Removes the amount from num.
int power(int div, int &num) {
    int power = 0;
    while(num % div == 0) {
        num /= div;
        power++;
    }
    return power;
}

// Gets the number of primes possible by checking all numbers inbetween 2 and the number inclusive
int nPrimes(int n) {
    int count = 0;
    for(int i = n; i >= 2; i--) {
        if(n % i == 0) {
            if(isPrime(i)) count++;
        }
    }
    return count;
}

// Frees memory
void cleanUp(Primes *primes) {
    delete []primes->pStrAry;
    delete primes;
}

// Calculates all prime factors
Primes *factor(int n) {
    Primes *primes = new Primes;
    primes->n = n;
    primes->nPrimes = nPrimes(n);
    primes->pStrAry = new Prime[primes->nPrimes];
    int prInd = 0;
    for(int i = n; i >= 2; i--) {
        if(n == 1) break;
        if(n % i == 0) {
            if(isPrime(i)) {
                primes->pStrAry[prInd].prime = i;
                primes->pStrAry[prInd].power = power(i, n);
                prInd++;
            }
        }
    }
    return primes;
}
// Prints the number and it's primes with their power.
void prtPrms(const Primes *primes) {
    cout << primes->n << " =";
    for(int i = primes->nPrimes - 1; i >= 0; i--) {
        cout << " " << primes->pStrAry[i].prime << "^" << static_cast<int>(primes->pStrAry[i].power);
    }
    cout << endl;
}
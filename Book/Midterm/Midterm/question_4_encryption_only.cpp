/* 
 * File:   question_4_encryption_only.cpp
 * Author: Matthew Madrigal
 * Created on November 2nd, 2025, 10:32 am,
 * Purpose:  To encrypt messages consisting of the numbers 0-7.
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Math/Science/Conversions only

//Function Prototypes
bool valMessage(string);

//Execution Begins Here
int main(int argc, char** argv) {
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

    //Exit the Program
    return 0;
}

// Validates the user input is valid (multiple digits all between 0 and 7 inclusive)
bool valMessage(string input) {
    if(input.length() != 4) return false;
    for(int i = 0; i < input.length(); i++) {
        if(!isdigit(input[i]) || input[i] > '7') return false;
    }
    return true;
}
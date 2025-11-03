/* 
 * File:   encryption.cpp
 * Author: Matthew Madrigal
 * Created on November 2nd, 2025, 11:11 am,
 * Purpose: To decrypt messages consisting of the numbers 0-7.
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Math/Science/Conversions only

//Function Prototypes
bool valMessage(string);
bool valMessMin(string);

//Execution Begins Here
int main(int argc, char** argv) {
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

// Basically the same as the valMessage but ignoring check for 8 and 9 that way the program can check if there is an error in the transmission
bool valMessMin(string input) {
    if(input.length() != 4) return false;
    for(int i = 0; i < input.length(); i++) {
        if(!isdigit(input[i])) return false;
    }
    return true;
}
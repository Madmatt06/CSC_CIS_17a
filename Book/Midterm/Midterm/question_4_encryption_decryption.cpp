/* 
 * File:   question_4_encryption_decryption.cpp
 * Author: Matthew Madrigal
 * Created on November 3rd, 2025, 10:19 am,
 * Purpose: To encrypt and decrypt messages consisting of the numbers 0-7.
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Math/Science/Conversions only

//Function Prototypes
bool valMessage(string);
bool valMessMin(string);
void encrypt();
void decrypt();

//Execution Begins Here
int main(int argc, char** argv) {
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
    
    //Exit the Program
    return 0;
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
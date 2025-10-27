/* 
 * File:   main.cpp
 * Author: Matthew Madrigal
 * Created on October 26th, 2025, 5:44 pm,
 * Purpose:  To take in a file and capitalize the first letter in every sentence while making everything else lowercase.
 */

//System Libraries
#include <iostream>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants - Math/Science/Conversions only

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    fstream input, output;
    string inName, outName;
    char let;   // Letter or character read from the file
    bool cap;   // If the next letter should be capitalized
    
    //Initialize Variables
    // Gets file names from user
    cout << "Enter a file to read from: ";
    cin >> inName;
    cout << "Enter a file to write to: ";
    cin >> outName;
    // Opens files
    input.open(inName, ios::in);
    if(input.fail()) {
        cout << "Failed to open source file" << endl;
        return 0;
    }
    output.open(outName, ios::out);
    if(output.fail()) {
        cout << "Failed to write to file" << endl;
        return 0;
    }
    cap = true;

    //The Process -> Map Inputs to Outputs
    // Go through each character, uppercase if needed, lowercase if needed, keep track of periods, and then write to output.
    while(input.get(let)) {
        if(cap && isalpha(let)) {
            let = toupper(let);
            cap = false;
        } else if(let == '.') {
            cap = true;
        } else if(isalpha(let)) {
            let = tolower(let);
        }
        output << let;
    }
    // Close files
    input.close();
    output.close();
    
    //Display Inputs/Outputs
    cout << "Finished writing to output file." << endl;

    //Exit the Program
    return 0;
}
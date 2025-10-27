/* 
 * File:   main.cpp
 * Author: Matthew Madrigal
 * Created on October 26th, 2025, 9:08 pm,
 * Purpose:  To save a file that is an encrypted version of the original file
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
    const string in = "data.txt";
    const string out = "encoded.txt";
    const int secret = 8;   // The book gives this as an example of a simple encryption type I can use
    char let;
    fstream fIn, fOut;
    //Initialize Variables
    //Opens files and if fails, exits
    fIn.open(in, ios::in);
    if(fIn.fail()) {
        cout << "Could not find source file" << endl;
        return 0;
    }
    fOut.open(out, ios::out);
    if(fOut.fail()) {
        cout << "Could not write to file" << endl;
        return 0;
    }
    //The Process -> Map Inputs to Outputs
    // Gets each character and shifts it by the secret amount
    while(fIn.get(let)) {
        let += secret;
        fOut << let;
    }
    //Display Inputs/Outputs
    // Nothing to display
    //Exit the Program
    fIn.close();
    fOut.close();
    return 0;
}
/* 
 * File:   main.cpp
 * Author: Matthew Madrigal
 * Created on October 26th, 2025, 6:40 pm,
 * Purpose:  To store structures in a file. A spinoff of the previous corperate sales data assignment question 1 (assignment 3)
 */

//System Libraries
#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

// Structures
struct Division {
    char name[10];
    float fiQuar;
    float sQuar;
    float tQuar;
    float foQuar;
    float year;
};

//Function Prototypes
void writeData(fstream &, Division);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    // All of the divisions
    Division divsN;
    Division divsW;
    Division divsE;
    Division divsS;
    fstream file;
    
    //Initialize Variables
    // Names the divisions
    strncpy(divsN.name, "North", 10);
    strncpy(divsW.name, "West", 10);
    strncpy(divsE.name, "East", 10);
    strncpy(divsS.name, "South", 10);
    file.open("data.bin", ios::out | ios::binary);
    
    
    
    //Process or map Inputs to Outputs
    // Gets and calculates data for North Division
    cout << divsN.name << endl;
    cout << "Enter first-quarter sales:" << endl;
    cin >> divsN.fiQuar;
    cout << "Enter second-quarter sales:" << endl;
    cin >> divsN.sQuar;
    cout << "Enter third-quarter sales:" << endl;
    cin >> divsN.tQuar;
    cout << "Enter fourth-quarter sales:" << endl;
    cin >> divsN.foQuar;
    divsN.year = divsN.fiQuar + divsN.sQuar + divsN.tQuar + divsN.foQuar;
    // Writes to data file
    writeData(file, divsN);
    
    // Gets and calculates data for West Division
    cout << divsW.name << endl;
    cout << "Enter first-quarter sales:" << endl;
    cin >> divsW.fiQuar;
    cout << "Enter second-quarter sales:" << endl;
    cin >> divsW.sQuar;
    cout << "Enter third-quarter sales:" << endl;
    cin >> divsW.tQuar;
    cout << "Enter fourth-quarter sales:" << endl;
    cin >> divsW.foQuar;
    divsW.year = divsW.fiQuar + divsW.sQuar + divsW.tQuar + divsW.foQuar;
    // Writes to data file
    writeData(file, divsW);
    
    // Gets and calculates data for East Division
    cout << divsE.name << endl;
    cout << "Enter first-quarter sales:" << endl;
    cin >> divsE.fiQuar;
    cout << "Enter second-quarter sales:" << endl;
    cin >> divsE.sQuar;
    cout << "Enter third-quarter sales:" << endl;
    cin >> divsE.tQuar;
    cout << "Enter fourth-quarter sales:" << endl;
    cin >> divsE.foQuar;
    divsE.year = divsE.fiQuar + divsE.sQuar + divsE.tQuar + divsE.foQuar;
    // Writes to data file
    writeData(file, divsE);
    
    // Gets and calculates data for South Division
    cout << divsS.name << endl;
    cout << "Enter first-quarter sales:" << endl;
    cin >> divsS.fiQuar;
    cout << "Enter second-quarter sales:" << endl;
    cin >> divsS.sQuar;
    cout << "Enter third-quarter sales:" << endl;
    cin >> divsS.tQuar;
    cout << "Enter fourth-quarter sales:" << endl;
    cin >> divsS.foQuar;
    divsS.year = divsS.fiQuar + divsS.sQuar + divsS.tQuar + divsS.foQuar;
    // Writes to data file
    writeData(file, divsS);

    //Display Outputs

    //Exit stage right!
    file.close();
    return 0;
}

void writeData(fstream &file, Division data) {
    file.write(reinterpret_cast<char *>(&data), sizeof(data));
}
/* 
 * File: main.cpp
 * Author: Matthew Madrigal
 * Created on: October 21st, 2025, 3:38pm
 * Purpose: To demonstrate use of a structure storing data
 */

//System Libraries
#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
// Structure for Divisions
struct Division {
    string name;
    float fiQuar;
    float sQuar;
    float tQuar;
    float foQuar;
    float total;
    float average;
};

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    // All of the divisions
    Division divsN;
    Division divsW;
    Division divsE;
    Division divsS;
    
    //Initialize Variables
    // Names the divisions
    divsN.name = "North";
    divsW.name = "West";
    divsE.name = "East";
    divsS.name = "South";
    
    
    
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
    divsN.total = divsN.fiQuar + divsN.sQuar + divsN.tQuar + divsN.foQuar;
    divsN.average = divsN.total / 4;
    cout << "Total Annual sales:$" << setprecision(2) << fixed << divsN.total << endl;
    cout << "Average Quarterly Sales:$" << setprecision(2) << fixed << divsN.average << endl;
    
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
    divsW.total = divsW.fiQuar + divsW.sQuar + divsW.tQuar + divsW.foQuar;
    divsW.average = divsW.total / 4;
    cout << "Total Annual sales:$" << setprecision(2) << fixed << divsW.total << endl;
    cout << "Average Quarterly Sales:$" << setprecision(2) << fixed << divsW.average << endl;
    
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
    divsE.total = divsE.fiQuar + divsE.sQuar + divsE.tQuar + divsE.foQuar;
    divsE.average = divsE.total / 4;
    cout << "Total Annual sales:$" << setprecision(2) << fixed << divsE.total << endl;
    cout << "Average Quarterly Sales:$" << setprecision(2) << fixed << divsE.average << endl;
    
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
    divsS.total = divsS.fiQuar + divsS.sQuar + divsS.tQuar + divsS.foQuar;
    divsS.average = divsS.total / 4;
    cout << "Total Annual sales:$" << setprecision(2) << fixed << divsS.total << endl;
    cout << "Average Quarterly Sales:$" << setprecision(2) << fixed << divsS.average;
    //Display Outputs
    
    //Exit stage right!
    return 0;
}

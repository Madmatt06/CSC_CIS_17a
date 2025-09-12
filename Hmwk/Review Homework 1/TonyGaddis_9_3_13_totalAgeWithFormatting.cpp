/* 
 * File:   TonyGaddis_9_3_13_totalAgeWithFormatting.cpp
 * Author: Matthew Madrigal
 * Created on September 11, 2025, 1:51 pm",
 * Purpose:  To print a variable called totalAge in a field of 12 spaces in fixed-point notation with a precision of 4 decimal places
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    const int width = 12;
    const int precision = 4;
    int totalAge;
    //Initialize Variables
    totalAge = 15.37451234124123;
    
    //Display Inputs/Outputs
    cout << fixed << setprecision(precision) << setw(width) << totalAge << endl;

    //Exit the Program
    return 0;
}
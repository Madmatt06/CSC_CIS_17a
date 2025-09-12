/* 
 * File:   main.cpp
 * Author: Matthew Madrigal
 * Created on September 11, 2025, 11:21 pm,
 * Purpose: To Convert from dollar to Yen and Euros
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    const double YEN = 98.93;
    const double EUROS = 0.74;
    double usd, yenConv, euroConv;
    //Initialize Variables
    cout << "Enter a dollar amount (0.00)";
    cin >> usd;
    //The Process -> Map Inputs to Outputs
    yenConv = usd*YEN;
    euroConv = usd*EUROS;
    //Display Inputs/Outputs
    cout << fixed << setprecision(2);
    cout << "Yen: " << yenConv << endl << "Euros: " << euroConv << endl;
    //Exit the Program
    return 0;
}
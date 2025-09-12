/* 
 * File:   main.cpp
 * Author: Matthew Madrigal
 * Created on September 11, 2025, 23:14 pm,
 * Purpose: To convert fahrenheit to celcius
 */

//System Libraries
#include <iostream>
using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    double ratio = 9.0/5.0;
    int offset = 32;
    int fahren;
    int celci;
    
    //Initialize Variables
    cout << "Enter a temperature in Celcius: ";
    cin >> celci;
    //The Process -> Map Inputs to Outputs
    fahren = (celci*ratio) + offset;
    //Display Inputs/Outputs
    cout << "Fahrenheit: " << fahren << endl;
    //Exit the Program
    return 0;
}
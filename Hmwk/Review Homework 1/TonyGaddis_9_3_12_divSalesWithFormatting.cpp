/* 
 * File:   TonyGaddis_9_3_12_divSalesWithFormatting.cpp
 * Author: Matthew Madrigal
 * Created on September 11, 2025, 13:26 AM
 * Purpose:  To print a variable called divSales in a field of 8 spaces with fixed point notation and a precision of 2 decimal places
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    const int width = 8;
    const int precision = 2;
    double divSales; // Text book problem wants precision of 4 decimal places so to demonstrate that it works, a double was used.
    
    //Initialize Variables
    divSales =  223.64243642;
    
    //Display Inputs/Outputs
    cout << fixed << setprecision(precision) << setw(width) << divSales << endl;

    //Exit the Program
    return 0;
}


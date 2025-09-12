/* 
 * File:   main.cpp
 * Author: Matthew Madrigal
 * Created on September 11, 2025, 2:07 pm
 * Purpose:  To ask the user for a month and year, and then display the number of days in it.
 */

//System Libraries
#include <iostream>
using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {    
    //Declare Variables
    // Constants
    const string promptM = "Enter a month (1-12): ";                //Prompt that is printed to get month from user
    const string promptY = "Enter a year: ";                        //Prompt that is printed to get month from user
    const string outSuffix = " days";                               //What to print after the number of days
    const string boundsErr = "Input was not part of bounds 1-12";   //What to print if the user gives a month thats out of bounds
    const int minM = 1;                                             //Minimum input for month
    const int maxM = 12;                                            //Maximum input for month
    const int leapCheck1 = 100;                                     //First number of 1st set to check if divisible by for leap year
    const int leapCheck2 = 400;                                     //Second number of 1st set to check if divisible by for leap year
    const int leapCheck3 = 4;                                       //Last seperate number to check if divisible by for leap year (not part of first set)

    //User generated variables
    int month, year;

    //Output Variables
    int days;

    //Initialize Variables
    month = 0;
    year = 0;
    //Repeats until recieves valid input
    while(month < minM || month > maxM) {
        cout << promptM;
        cin >> month;
        if(month < minM || month > maxM) {
            cout << boundsErr << endl;
        }
    }
    cout << promptY;
    cin >> year;
    //The Process -> Map Inputs to Outputs
    switch(month) {
        //Months 1 3 5 7 8 10 12 are 31 days
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
        days = 31;
        break;
        
        //Months 4 6 9 11 are 30 days
        case 4:
        case 6:
        case 9:
        case 11:
        days = 30;
        break;

        // Feburary leap year check. 29 if leap year, 28 if normal.
        case 2:
        if((month%leapCheck1 == 0 && month%leapCheck2 == 0) || !month%leapCheck3 == 0) {
            cout << "leap year" << endl;
            days = 29;
        } else {
            days = 28;
        }
        break;
        default:
        days = -1;  //Useful for debugging
    }

    //Display Inputs/Outputs
    cout << days << outSuffix << endl;

    //Exit the Program
    return 0;
}
/* 
 * File:   TonyGaddis_9_6_7_celsiusTemperatureTable.cpp
 * Author: Matthew Madrigal
 * Created on September 11, 2025, 20:34 pm",
 * Purpose:  To demonstrate a function which converts from fahrenheit to celsius by display a table
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Function Prototypes
int fahrenheitToCelcius(int temp);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    const int start = 0;    //Where the table should start
    const int end = 20;     //Where the table should end
    const int cellWidth = 10;
    int temp;
    //Initialize Variables
    temp = 0;
    
    //Display Inputs/Outputs
    cout << setw(cellWidth) << "Fahrenheit" << setw(cellWidth) << "Celcius" << endl;
    for(int fahren = start; fahren <= end; fahren++) { //fahren is a tempreature in fahrenheit
        temp = fahrenheitToCelcius(fahren);
        cout << setw(cellWidth) << fahren << setw(cellWidth) << temp << endl;
    }
    //Exit the Program
    return 0;
}

int fahrenheitToCelcius(int temp) {
    const double ratio = 5.0/9.0;   //Ratio used in converted from fahrenheit to celcius
    const int offset = 32;      //Offset used in converted from fahrenheit to celcius
    return ratio*(temp-offset);
}
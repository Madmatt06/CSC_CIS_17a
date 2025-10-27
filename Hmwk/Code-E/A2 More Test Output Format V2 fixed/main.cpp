/* 
 * File:main.cpp
 * Author:Matthew Madrigal
 * Date:September 15th 2025 11:08pm
 * Purpose:To demonstrate usage of setw, fixed, and setprecision to format the output properly.
 * Version: 1
 */

//System Libraries - Post Here
#include <iostream>
//Library for our functions utilized in this question.
#include <iomanip>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here when needed
    
    //Declare variables or constants here
    //7 characters or less
    const int widthS = 9; //Shorter sections
    const int widthL = 10; //Wider sections
    double a,b,c,d;
    
    //Initialize or input data here
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    //Display initial conditions, headings here
    
    //Process inputs  - map to outputs here
    
    //Format and display outputs here
    cout << fixed << setprecision(0) << setw(widthS) << a << setprecision(1) << setw(widthL) << a << setprecision(2) << setw(widthL) << a << endl;
    cout << setprecision(0) << setw(widthS) << b << setprecision(1) << setw(widthL) << b << setprecision(2) << setw(widthL) << b << endl;
    cout << setprecision(0) << setw(widthS) << c << setprecision(1) << setw(widthL) << c << setprecision(2) << setw(widthL) << c << endl;
    cout << setprecision(0) << setw(widthS) << d << setprecision(1) << setw(widthL) << d << setprecision(2) << setw(widthL) << d;
    
    //Exit stage left
    return 0;
}
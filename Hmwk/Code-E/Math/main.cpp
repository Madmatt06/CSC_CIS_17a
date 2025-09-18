/* 
 * File:main.cpp
 * Author:Matthew Madrigal
 * Date:September 15th 2025 11:05pm
 * Purpose:To demonstrate performing math operations while getting the correct output format
 * Version: 1
 */

//System Libraries - Post Here
#include <iostream>
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
    //3 integers a b c  
    /*
    a + b
    b + a - c
    (a+b)*c
    (a/b)*c
    (a*c)/b
    */

    //Initialize or input data here
    int a, b, c;
   
    //Process inputs  - map to outputs here
    cin >> a;
    cin >> b;
    cin >> c;
    
    //Format and display outputs here
    cout <<"A + B is: " << a+b << endl;
    cout <<"B + A - C is: " << a+b-c << endl;
    cout <<"(A + B) * C is: " << (a+b)*c << endl;
    cout <<"(A / B) * C is: " << (a/b)*c<< endl; 
    cout <<"(A * C) / B is: " << (a*c)/b << endl;
    cout <<"A % B is: " << a%b << endl;
    //Clean up allocated memory here
    
    //Exit stage left
    return 0;
}
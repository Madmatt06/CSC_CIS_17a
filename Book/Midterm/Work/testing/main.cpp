/* 
 * File:   main.cpp
 * Author: Matthew Madrigal
 * Created on CURRENT_MONTH CURRENT_DATE, CURRENT_YEAR, HOUR:MINUTE am,
 * Purpose:  
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - Math/Science/Conversions only

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    double test = 1;
    long double truth = 1;
    long long int sub = 0;
    string input;
    while(test == truth) {
        sub++;
        test = 1;
        truth = 1;
        test = 1;
        for(int i = sub; i > 1; i--) {
            test *= i;
            truth *= i;
        }
        cout << sub << " test is " << fixed << setprecision(0) << test << " and truth is " << truth << endl;
        cin.ignore();
    }
    cout << "Max is " << sub-1 << endl;
    return 0;
}

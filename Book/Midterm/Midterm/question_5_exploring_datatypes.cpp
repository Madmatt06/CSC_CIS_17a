/* 
 * File:   question_5_exploring_datatypes.cpp
 * Author: Matthew Madrigal
 * Created on November 3rd, 2025, 6:00 pm,
 * Purpose:  To show the results I found for how large I can make a factorial before it overflows
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Math/Science/Conversions only

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Display Inputs/Outputs
    cout<<"char 5" << endl
    << "unsigned char 5" << endl 
    << "short int 7" << endl
    << "unsigned short int 8" << endl
    << "int 12" << endl
    << "unsigned int 12" << endl
    << "long int 20" << endl
    << "unsigned long int 20" << endl
    << "long long int 20" << endl
    << "unsigned long long int 20" << endl
    << "float 34 (float lost precision and was wrong at 14. Float kept storing larger values up to 34. After 34 cout prints infinity)" << endl
    << "double 170 (double may have lost precision and was wrong or my calculator may have been wrong at 22. double kept storing larger values up to 170. After 170 cout prints infinity)" << endl
    << "long double 170 (long double may have lost precision and was wrong or my calculator may have been wrong at 22. long double kept storing larger values up to 170. After 170 cout prints infinity)"<<endl;

    //Exit the Program
    return 0;
}
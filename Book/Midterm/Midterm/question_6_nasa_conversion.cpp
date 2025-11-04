/* 
 * File:   question_6_nasa_conversion.cpp
 * Author: Matthew Madrigal
 * Created on November 3rd, 2025, 5:56 pm,
 * Purpose:  To show my answers for the nasa conversion question
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Math/Science/Conversions only

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    cout<<"Part a:" << endl
        << "49.1875 base 10 in base 16 = 31.3, base 2 = 110001.0011, base 8 = 61.16, and nasa format = 01100010011000000000000000000110" << endl
        << "3.07421675 base 10 in base 16 = 3.13, base 2 = 11.00010011, base 8 = 3.046, and nasa format = 01100010011000000000000000000010" << endl
        << "0.2 base 10 in base 16 = 0.3333 repeating, base 2 = 0.001100110011 repeating, base 8 = 0.1463 repeating, and nasa format = 01100110011001100110011011111110" << endl;
    cout << "Part b:" << endl
        << "-49.1875 base 10 in nasa format: 10011101101000000000000000000110" << endl
        << "-3.07421675 base 10 in nasa format: 10011101101000000000000000000010" << endl
        << "0.2 base 10 in nasa format: 10011001100110011001101011111110" << endl;
    cout << "Part c:" << endl
        << "69999902 nasa format to decimal = 3.299999714" << endl
        << "69999903 nasa format to decimal = 6.599999428" << endl
        << "966667FF nasa format to decimal = -0.412499964" << endl;
    return 0;
}
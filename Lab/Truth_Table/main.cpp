/* 
 * File:   main.cpp
 * Author: Matthew Madrigal
 * Created on September 8th 2025 9:53 am
 * Purpose:  To tell the Truth
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    bool x,y;
    
    //Display the Heading
    cout<<"X Y !X !Y X&&Y X||Y X^Y X^Y^X X^Y^Y !(X&&Y) !X||!Y "<<
          " !(X||Y) !X&&!Y"<<endl;
    
    //Keeps creating rows until no more input is detected
    while(cin >> x) {
        cin >> y;
        cout<<(x?'T':'F')<<" "
            <<(y?'T':'F')<<"  "
            <<(!x?'T':'F')<<"  "
            <<(!y?'T':'F')<<"   "
            <<(x&&y?'T':'F')<<"    "
            <<(x||y?'T':'F')<<"   "
            <<(x^y?'T':'F')<<"    "
            <<(x^y^x?'T':'F')<<"     "
            <<(x^y^y?'T':'F')<<"       "
            <<(!(x&&y)?'T':'F')<<"      "
            <<(!x||!y?'T':'F')<<"        "
            <<(!(x||y)?'T':'F')<<"      "
            <<(!x&&!y?'T':'F')<<endl;
    }
    
    //Formatting to match TestCases
    cout << endl;
    

    //Exit
    return 0;
}
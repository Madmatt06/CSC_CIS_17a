/* 
 * File:   main.cpp
 * Author: Matthew Madrigal
 * Created on September 21st, 8:51pm
 * Purpose:  Input something, output it reversed with some modifications
 * Note:Range should be 5 digits, 321 = 00321 reverse = 12300 before subtraction
 *      12300 - 999 = 11301 after subtraction
 *      12300 = 00321 = 321 after reversal and no subtraction
 */

//System Libraries Here
#include <iostream>//cin,cout,endl
#include <cstring> //strlen()
using namespace std;
//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here


bool  inRange(const char [],unsigned short &);//Output true,unsigned or false
bool  reverse(unsigned short,signed short &);//Output true,short or false
short subtrct(signed short,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;     //More than enough
    char  digits[SIZE];    //Character digits or not
    unsigned short unShort;//Unsigned short
    short snShort;         //Signed short
    
    //Input or initialize values Here
    cout<<"Reverse a number and subtract if possible."<<endl;
    cout<<"Input a number in the range of an unsigned short"<<endl;
    cin>>digits;
    
    //Test if it is in the Range of an unsigned short
    if(!inRange(digits,unShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    //Reverse and see if it falls in the range of an signed short
    if(!reverse(unShort,snShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    //Now subtract if the result is not negative else don't subtract
    snShort=subtrct(snShort,999);
    
    //Output the result
    cout<<snShort<<endl;
    
    //Exit
    return 0;
}

bool inRange(const char array[],unsigned short &num) {
    int size = strlen(array);
    unsigned int numL = 0;
    if(size > 5) { //Checks to see if its even possible to be in range (less than 6 digits for a short)
        return false;
    }
    //Confirms all chars are a digit and then puts it into an int.
    for(int index = 0; index < size; index++) {
        if(array[index] < '0' || array[index] > '9') {
            return false;
        }
        numL *= 10;
        int digit = array[index]-'0';
        numL += digit;
    }
    //Checks if its in range of the short unsigned
    if(numL > 65535) {
        return false;
    }
    num = numL;
    return true;
}
bool reverse(unsigned short num,signed short &revNum) {
    unsigned int revNumL = 0;
    int index = 0;
    //Reverses number taking into account the possible leading 0s
    while(index < 5) {
        revNumL *= 10;
        revNumL += num%10;
        num /= 10;
        index++;
    }
    //Checks if its in range of signed short
    if(revNumL > 32767) {
        return false;
    }
    revNum = revNumL;
    return true;
}
short subtrct(signed short num,int sub) {
    short int diff = num - sub;
    //Returns original number if the subtracted number is negative. Returns subtracted number otherwise.
    if(diff < 0) {
        return num;
    } else {
        return diff;
    }
}
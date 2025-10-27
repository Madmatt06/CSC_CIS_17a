/* 
 * Purpose:  Searching for multiple occurrence of patterns
 * Note:  cout proceeds to null terminator, cin reads to end of line
 *        for character arrays
 * 
 */

//System Libraries Here
#include <iostream>//cin,cout,getline()
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//PI, e, Gravity, or conversions

//Function Prototypes Begins Here
//srch1 utility function Input->start position, Output->position found or not
//srch1 is a simple linear search function, repeat in srchAll till all found
//srch1 Input->sentence, pattern, start position Output-> position found
//Remember arrays start at index/position 0
//srchAll Input->sentence, pattern Output->position array
int  srch1(const char [],const char [],int);//Search for 1 occurrence
void srchAll(const char [],const char [],int []);//Search for all occurrences
void print(const char []);//Print the character arrays
void print(const int []); //Print the array of indexes where the pattern found

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int LINE=81;               //Size of sentence or pattern to find
    char sntnce[LINE],pattern[LINE]; //80 + null terminator
    int match[LINE];                 //Index array where pattern was found
    
    //Input a sentence and a pattern to match
    cout<<"Match a pattern in a sentence."<<endl;
    cout<<"Input a sentence"<<endl;
    cin.getline(sntnce,LINE);
    cout<<"Input a pattern."<<endl;
    cin.getline(pattern,LINE);
    
    //Search for the pattern
    //Input the sentence and pattern, Output the matching positions
    //Remember, indexing starts at 0 for arrays.
    srchAll(sntnce,pattern,match);
    
    //Display the inputs and the Outputs
    cout<<endl<<"The sentence and the pattern"<<endl;
    print(sntnce);
    print(pattern);
    cout<<"The positions where the pattern matched"<<endl;
    print(match);
    
    //Exit
    return 0;
}

int srch1(const char array1[],const char array2[],int start) {
    //To stop constantly checking the size
    int arr1Len = strlen(array1);
    int arr2Len = strlen(array2);
    //Checks where the first instance of the pattern exists
    for(int index = start; index < arr1Len; index++) {
        if(index+arr2Len > arr1Len) {
            return -1; //Returns -1 if it wont find it because it will have to read out of bounds
        }
        for(int sIndex = 0; sIndex < arr2Len; sIndex++) {
            if(array1[index+sIndex] != array2[sIndex]) {
                break;
            }
            if(sIndex == arr2Len-1) {
                return index;
            }
        }
    }
    return -1; //Returns -1 if it could not find it
}
void srchAll(const char array1[],const char array2[],int finds[]) {
    int index = 0;
    int offset = 0;
    int arr1Len = strlen(array1); //Stops constant checking of size
    while(offset < arr1Len) { //Keeps searching after the previous find to see if there are more
        finds[index] = srch1(array1, array2, offset);
        if(finds[index] == -1) {
            break; //Nothing was found. Safe to leave loop.
        }
        offset = finds[index] + 1; //To tell the srch1 function to search after the previous found instance.
        index++;
    }
    finds[index] = -1; //Incase srch1 never returned -1 that way the print function knows when to end.
}
void print(const char array[]) {
    cout << array << endl;
}
void print(const int finds[]) {
    if(finds[0] == -1) {
        cout << "None" << endl; //For required formatting
    }
    int index = 0;
    while(finds[index] != -1) { //Print function stops when it finds a -1
        cout << finds[index] << endl;
        index++;
    }
}
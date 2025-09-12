/* 
 * File:   main.cpp
 * Author: Matthew Madrigal
 * Created on September 11, 2025, 21:10 pm,
 * Purpose:  To modify a binary search from the textbook to support int instead of string and demonstrate its used with 
 */

//System Libraries
#include <iostream>
#include <string>   //The excersice asks to use Program 8-8 as a skeleton to complete the problem.
                    //Program 8-8 has this in it, but I don't believe its neccesary for this code to work with the compiler I am using. (Clang++)
using namespace std;

//Function Prototypes
int binarySearch(const string array[], int numElems, string value);
void swap(string &, string &);
void selectionSort(string array[], const int SIZE);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    const int NUM_NAMES = 20;
    string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                               "Griffin, Jim", "Stamey, Marty" , "Rose, Geri",
                               "Taylor, Terri", "Johnson, Jill",
                               "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
                               "James, Jean", "Weaver, Jim", "Pore, Bob",
                               "Rutherford, Greg", "Javens, Renee",
                               "Harrison, Rose" , "Setzer, Cathy",
                               "Pike, Gordon" , "Holland, Beth"};
    string nameSearch;  //Name user wants to search for.
    int foundPos;       //Position the name was found
    
    //Initialize Variables
    cout << "Enter a name to search for: ";
    getline(cin, nameSearch);
    
    //The Process -> Map Inputs to Outputs
    selectionSort(names, NUM_NAMES);
    foundPos = binarySearch(names, NUM_NAMES, nameSearch);
    
    //Display Inputs/Outputs
    cout << "The name '" << names[foundPos] << "' was found at position " << foundPos << endl;

    //Exit the Program
    return 0;
}

//Searches through the list for a name.
int binarySearch(const string array[], int numElems, string value) {
    int first = 0,
        last = numElems-1,
        middle,
        position = -1;
    bool found = false;
    while(!found && first <= last) {
        middle = (first+last)/2;    //Calculate midpoint
        if (array[middle] == value) {
            found = true;
            position = middle;
        }
        else if (array[middle] > value)
            last = middle - 1;
        else
            first = middle + 1;
    }
    return position;
}

//Helper function for sort function
void swap(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}

//Sorts list since binary search only works on a sorted list.
void selectionSort(string array[], const int SIZE) {
    int minIndex;
    string minValue;

    for(int start = 0; start < (SIZE-1); start++) {
        minIndex = start;
        minValue = array[start];
        for(int index = start + 1; index < SIZE; index++) {
            if(array[index] < minValue) {
                minValue = array[index];
                minIndex = index;
            }
        }
        swap(array[minIndex], array[start]);
    }
}

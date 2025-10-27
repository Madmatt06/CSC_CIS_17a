/* 
 * File:   main.cpp
 * Author: Matthew Madrigal
 * Created on October 26th, 2025, 6:96 pm,
 * Purpose:  To take an array and write it to a binary file.
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - Math/Science/Conversions only

//Function Prototypes
void arrayToFile(string, int*, int);
void fileToArray(string, int*, int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    const int size = 5;
    int arr[size] = {22, 13432, 2, 75452, 134531};
    string save;
    //Initialize Variables
    save = "data.bin";

    //The Process -> Map Inputs to Outputs
    // Shows array before performing file save and load operations
    cout << setw(15) << "Current array: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    // Performs file save and load operation
    arrayToFile(save, arr, size);
    fileToArray(save, arr, size);

    //Display Inputs/Outputs
    //Shows array after loading file
    cout << setw(15) << "New array: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    //Exit the Program
    return 0;
}

void arrayToFile(string file, int *arr, int size) { // Writes the data if possible
    fstream out;
    out.open(file, ios::out | ios::binary);
    if(out.fail()) {
        cout << "Failed to open file" << endl;
        return;
    }

    out.write(reinterpret_cast<char *>(arr), size * sizeof(int));
    out.close();
}

void fileToArray(string file, int *arr, int size) { // Reads the data if possible
    fstream in;
    in.open(file, ios::in | ios::binary);
    if(in.fail()) {
        cout << "Failed to open file" << endl;
        return;
    }

    in.read(reinterpret_cast<char *>(arr), size * sizeof(int));
    in.close();
}
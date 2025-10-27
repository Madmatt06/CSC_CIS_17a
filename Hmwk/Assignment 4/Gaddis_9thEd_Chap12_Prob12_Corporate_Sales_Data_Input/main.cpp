/* 
 * File:   main.cpp
 * Author: Matthew Madrigal
 * Created on October 26th, 2025, 7:44 pm,
 * Purpose:  To take in the save data from the previous problem (11), read it, and display information.
 */

//System Libraries
#include <iostream>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants - Math/Science/Conversions only

//Structures
struct Division {
    char name[10];
    float fiQuar;
    float sQuar;
    float tQuar;
    float foQuar;
    float year;
};

//Function Prototypes
void readData(fstream &, Division &);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE = 4;
    const int QUAR = 4;
    Division divs[SIZE];    // Stores each devision
    fstream file;
    float quar[QUAR] = {0, 0, 0, 0};    // Stores the quarters of all devisions added
    float year = 0, highest = 0, lowest = 0;
    
    //Initialize Variables
    file.open("data.bin", ios::in | ios::binary);
    for(int i = 0; i < SIZE; i++) {
        readData(file, divs[i]); // Reads the data for each division
    }
    file.close();

    //The Process -> Map Inputs to Outputs
    // Adds the quarters of each devision
    for(int i = 0; i < SIZE; i++) {
        quar[0] += divs[i].fiQuar;
        quar[1] += divs[i].sQuar;
        quar[2] += divs[i].tQuar;
        quar[3] += divs[i].foQuar;
    }

    highest = quar[0];
    lowest = quar[0];
    for(int i = 0; i < QUAR; i++) { // Finds highest, lowest, and adds all quarters
        if(highest < quar[i]) {
            highest = quar[i];
        }
        if(lowest > quar[i]) {
            lowest = quar[i];
        }
        year += quar[i];
    }

    
    //Display Inputs/Outputs
    cout << "Total Corperate sales for each quarter" << endl;
    cout << "Quarter one: " << quar[0] << endl;
    cout << "Quarter two: " << quar[1] << endl;
    cout << "Quarter three: " << quar[2] << endl;
    cout << "Quarter four: " << quar[3] << endl;
    cout << "Yearly sales for divisions" << endl;
    for(int i = 0; i < SIZE; i++) {
        cout << divs[i].name << ": " << divs[i].year << endl;
    }
    cout << "Average sales for divisions" << endl;
    for(int i = 0; i < SIZE; i++) {
        cout << divs[i].name << ": " << divs[i].year / 4.0 << endl;
    }
    cout << "Highest quarter: " << highest << endl;
    cout << "Lowest quarter: " << lowest << endl;

    //Exit the Program
    return 0;
}

void readData(fstream &file, Division &data) {
    file.read(reinterpret_cast<char *>(&data), sizeof(data));
}
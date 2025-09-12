/* 
 * File:   Gaddis_Edi9_Chap7_Prob6_shortAnswerArrays.cpp
 * Author: Matthew Madrigal
 * Created on September 11, 2025, 9:15 pm ,
 * Purpose: To count the number of days rainy, sunny, and cloudy days in each month and all 3 months (June, July, nad August)
 */

//System Libraries
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    const string fileName = "RainOrShine.txt";
    const int rows = 3;
    const int columns = 30;
    const int cellWidth = 8;
    char days[rows][columns] = {0};
    int rowIndex = 0;
    int columnIndex = 0;
    ifstream file;
    char data;
    int rain[rows] = {0};  //Keeps track of number of rainy days for all 3 months
    int sun[rows] = {0};   //Keeps track of number of sunny days for all 3 months
    int cloud[rows] = {0}; //Keeps track of number of cloudy days for all 3 months
    int rainiestIndex = 0; //Keeps track of rainiest month
    int total[3] = {0};    //Keeps track of rain, clouds, and sun in that order across all months
    
    //Initialize Variables
    //Reads the file and loads the data
    file.open(fileName);
    while (file >> data) {
        if(rowIndex >= rows) {
            cout << "Rows out of range. Ending file read." << endl;    //Helpful for debugging and incase the file has the wrong data
            break;
        }
        days[rowIndex][columnIndex] = data;
        columnIndex++;
        if(columnIndex >= columns) {
            columnIndex = 0;
            rowIndex++;
        }
    }
    
    //The Process -> Map Inputs to Outputs
    //Calculates number of days in each month, and then all 3 months
    for(int rowIndex = 0; rowIndex < rows; rowIndex++) {
        for(int columnIndex = 0; columnIndex < columns; columnIndex++) {
            data = days[rowIndex][columnIndex];
            switch(data) {
                case 'R':
                rain[rowIndex]++;
                break;
                case 'C':
                cloud[rowIndex]++;
                break;
                case 'S':
                sun[rowIndex]++;
                break;
                default:
                cout << "uknown data found: " << data;
            }
        }
    }
    //Figure out which month is the rainiest
    for(int index = rainiestIndex; index < rows; index++) {
        if(rain[index] > rain[rainiestIndex]) {
            rainiestIndex = index;
        }
    }
    //Calculate total rain across all months
    for(int index = 0; index < rows; index++) {
        total[0] += rain[index];
    }
    //Calculate total cloud across all months
    for(int index = 0; index < rows; index++) {
        total[1] += cloud[index];
    }
    //Calculate total sun across all months
    for(int index = 0; index < rows; index++) {
        total[2] += sun[index];
    }
    //Display Inputs/Outputs
    //Displays results
    cout << setw(cellWidth) << "Month" << setw(cellWidth) << "Rain" << setw(cellWidth) << "Cloudy" << setw(cellWidth) << "Sunny" << endl;
    cout << setw(cellWidth) << "June" << setw(cellWidth) << rain[0] << setw(cellWidth) << cloud[0] << setw(cellWidth) << sun[0] << endl;
    cout << setw(cellWidth) << "July" << setw(cellWidth) << rain[1] << setw(cellWidth) << cloud[1] << setw(cellWidth) << sun[1] << endl;
    cout << setw(cellWidth) << "August" << setw(cellWidth) << rain[2] << setw(cellWidth) << cloud[2] << setw(cellWidth) << sun[2] << endl;
    cout << endl;
    cout << "Total" << endl;
    cout << setw(cellWidth) << "Rain" << setw(cellWidth) << "Cloudy" << setw(cellWidth) << "Sunny" << endl;
    cout << setw(cellWidth) << total[0] << setw(cellWidth) << total[1] << setw(cellWidth) << total[2] << endl;
    cout << endl << "Rainiest day is: ";
    switch(rainiestIndex) {
        case 0:
        cout << "June";
        break;
        case 1:
        cout << "July";
        break;
        case 2:
        cout << "August";
        break;
    }
    cout << endl;

    //Exit the Program
    file.close();
    return 0;
}
/* 
 * File:   main.cpp
 * Author: Matthew Madrigal
 * Created on September 28th, 2025, 9:07 PM
 */
#include <iostream>

using namespace std;

int **getData(int &,int &);                 //Get the Matrix Data
void printDat(const int * const *,int,int); //Print the Matrix
int **augment(const int * const *,int,int); //Augment the original array
void destroy(int **,int);                   //Destroy the Matrix, i.e., reallocate memory

int main(){
	//your code here
	int rows, cols;
	int **data = getData(rows, cols);
	int **augData = augment(data, rows, cols);
	printDat(data, rows, cols);
	cout << endl;
	printDat(augData, rows+1, cols+1);
	destroy(data, rows);
	destroy(augData, rows+1);
	return 0;
}

int **getData(int & rows,int & cols) {
    //Gets number of rows and columns needed
    cin >> rows;
    cin >> cols;
    //Creates 2D array
    int **data = new int*[rows];
    for(int row = 0; row < rows; row++) {
        data[row] = new int[cols];
    }
    //Fills 2D array
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) {
            cin >> data[row][col];
        }
    }
    return data;
}

void printDat(const int * const *data,int rows,int cols) {
    //Prints each column and array
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) {
            cout << data[row][col];
            if(col < cols-1) {
                cout << " ";
            }
        }
        if(row < rows-1) {
            cout << endl;
        }
    }
}
int **augment(const int * const *data,int rows,int cols) {
    //Expands the size by 1 for the columns and arrays
    int rowNew = rows+1;
    int colNew = cols+1;
    //Creates new array
    int **augData = new int*[rowNew];
    for(int row = 0; row < rowNew; row++) {
        augData[row] = new int[colNew];
    }
    //Fills array with an offset of 1 for the column and row
    for(int row = 1; row < rowNew; row++) {
        for(int col = 1; col < colNew; col++) {
            augData[row][col] = data[row-1][col-1];
        }
    }
    //Fills the first row with 0
    for(int col = 0; col < colNew; col++) {
        augData[0][col] = 0;
    }
    //Fills the first column with 0
    for(int row = 0; row < rowNew; row++) {
        augData[row][0] = 0;
    }
    return augData;
}
void destroy(int **data,int rows) {
    for(int row = 0; row < rows; row++) {
        delete []data[row];
    }
    delete []data;
}
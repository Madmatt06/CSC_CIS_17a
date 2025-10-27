/* 
 * File:   main.cpp
 * Author: Matthew Madrigal
 * Created on September 28th, 2025, 8:12 PM
 */
#include <iostream>

using namespace std;

int **getData(int &,int &);                 //Return the 2-D array and its size.
void prntDat(const int* const *,int,int);   //Print the 2-D Array
void destroy(int **,int,int);               //Deallocate memory
int sum(const int * const *, int,int);      //Return the Sum

int main(){
	//your code here
	int rows, cols;
	int **data = getData(rows, cols);
	prntDat(data, rows, cols);
	int add = sum(data, rows, cols);
	cout << add;
	destroy(data, rows, cols);
	return 0;
}

int **getData(int &rows, int &cols) {
    //Gets number of needed rows and cols
    cin >> rows;
    cin >> cols;
    //Creates 2D array
    int **data = new int*[rows];
    for(int row = 0; row < rows; row++) {
        data[row] = new int[cols];
    }
    //Fills array with data
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) {
            cin >> data[row][col];
        }
    }
    return data;
}

void prntDat(const int* const *data, int rows, int cols) {
    // Prints each row and column
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) {
            cout << data[row][col];
            if(col < cols-1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void destroy(int ** data,int rows,int cols) {
    //Frees each individual array inside and the main array
    for(int row = 0; row < rows; row++) {
        delete []data[row];
    }
    delete []data;
}

int sum(const int * const *data, int rows,int cols) {
    //Adds all the numbers in the array
    int sum = 0;
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) {
            sum += data[row][col];
        }
    }
    return sum;
}

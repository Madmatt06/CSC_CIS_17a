/* 
 * File:   main.cpp
 * Author: Matthew Madrigal
 * Created on September 28th, 2025, 6:20 PM
 */

#include <iostream>
#include <iomanip>

using namespace std;

int *getData(int &);         //Return the array size and the array
void prntDat(int *,int);    //Print the integer array
float *median(int *,int);  //Fill the median Array with the Float array size, the median, and the integer array data
void prntMed(float *);     //Print the median Array

int main(){
	//your code here
	int size;
	int *data = getData(size);
	prntDat(data, size);
	float *flData = median(data, size);
	prntMed(flData);
	delete []flData;
	delete []data;
	return 0;
}

int *getData(int &size) {
    cin >> size;                        //Get size of data
    int *medArr = new int[size];
    for(int i = 0; i < size; i++) {     //Takes input enough times to fill array
        cin >> medArr[i];
    }
    return medArr;
}

void prntDat(int *arr, int size) {
    for(int i = 0; i < size; i++) {     //Prints the whole array
        cout << arr[i];
        if(size-1 > i) {                // Prints a space only if its no the end
            cout << " ";
        }
    }
    cout << endl;
}

float *median(int *arr, int size) {
    float *data = new float[size+2];    
    data[0] = size+2;                   //Puts size of array in first element
    float med = 0;
    for(int i = 0; i < size; i++) {     //Adds all of the ints in the array
        data[i+2] = arr[i];
        med+= arr[i];
    }
    med /= size;                        //Calculates median by dividing by size
    data[1] = med;
    return data;
}

void prntMed(float *data) {
    int size = data[0];
    cout << size << " ";
    cout << fixed << setprecision(2);   //Formatting
    for(int i = 1; i < size; i++) {     //Prints whole array
        cout << data[i];
        if(i < size-1) {
            cout << " ";
        }
    }
}
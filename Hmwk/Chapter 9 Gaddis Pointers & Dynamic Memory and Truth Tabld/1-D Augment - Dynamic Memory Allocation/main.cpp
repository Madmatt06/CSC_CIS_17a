/* 
 * File:   main.cpp
 * Author: Matthew Madrigal
 * Created on September 28th, 2025, 9:07 PM
 */
#include <iostream>

using namespace std;

int *getData(int &);            //Read the array
int *augment(const int *,int);  //Augment and copy the original array
void prntAry(const int *,int);  //Print the array

int main(){
	//your code here
	int size;
	int *data = getData(size);
	int *augData = augment(data, size);
	prntAry(data, size);
	cout << endl;
	prntAry(augData, size+1);
	return 0;
}

int *getData(int &size) {
    cin >> size;                            //Gets the needed size
    int *data = new int[size];
    for(int ind = 0; ind < size; ind++) {   //Fills the array with data
        cin >> data[ind];
    }
    return data;
}

int *augment(const int *data,int size) {
    int newSize = size+1;
    int *augData = new int[newSize];            //Create an array one larger
    augData[0] = 0;
    for(int ind = 1; ind < newSize; ind++) {    //Fills the new array with an offset of 1
        augData[ind] = data[ind-1];
    }
    return augData;
}

void prntAry(const int *data,int size) {
    for(int ind = 0; ind < size; ind++) {       //Prints the whole array
        cout << data[ind];
        if(ind < size-1) {
            cout << " ";
        }
    }
}
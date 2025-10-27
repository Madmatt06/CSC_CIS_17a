/* 
 * File:   main.cpp
 * Author: Matthew Madrigal
 * Created on September 28th, 2025, 7:03 PM
 */
#include <iostream>

using namespace std;

int *getData(int &);            //Return the array size and the array from the inputs
int *sumAry(const int *,int);   //Return the array with successive sums
void prntAry(const int *,int);  //Print the array

int main(){
	//your code here
	int size;
	int *data = getData(size);
	prntAry(data, size);
	cout << endl;
	int *sum = sumAry(data, size);
	prntAry(sum, size);
	delete []data;
	delete []sum;
	return 0;
}

int *getData(int &size) {
    cin >> size; //Gets size to create the correctly sized array
    int *data = new int[size];
    for(int ind = 0; ind < size; ind++) { //Loads data into array
        cin >> data[ind];
    }
    return data;
}

int *sumAry(const int *data,int size) {
    int sum = 0;
    int *sumAr = new int[size];
    for(int ind = 0; ind < size; ind++) { //sums up previous elements and sets the current element to that
        sum += data[ind];
        sumAr[ind] = sum;
    }
    return sumAr;
}

void prntAry(const int *data,int size) {
    for(int ind = 0; ind < size-1; ind ++) { //Prints whole array.
        cout << data[ind] << " ";
    }
    cout << data[size-1];
}
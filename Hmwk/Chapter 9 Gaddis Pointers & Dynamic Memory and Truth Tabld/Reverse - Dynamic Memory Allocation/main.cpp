/* 
 * File:   main.cpp
 * Author: Matthew Madrigal
 * Created on September 28th, 2025, 6:23 PM
 */

#include <iostream>

using namespace std;

int *getData(int &);            //Fill the array
int *sort(const int *,int);     //Sort smallest to largest
int *reverse(const int *,int);  //Sort in reverse order
void prntDat(const int *,int);  //Print the array

int main(){
	//your code here
	int size;
	int *data = getData(size);
	int *dataS = sort(data, size);
	int *dataR = reverse(dataS, size);
	prntDat(dataS, size);
	cout << endl;
	prntDat(dataR, size);
	delete []data;
	delete []dataS;
	//delete []dataR;
	return 0;
}

//Gets size needed for array and then loads input in to array
int *getData(int &size) {
    cin >> size;
    int *data = new int[size];
    for(int i = 0; i < size; i++) {
        cin >>data[i];
    }
    return data;
}

//Sorts array smallest to largest
int *sort(const int *dataC, int size) {
    int *data = new int[size];
    for(int ind = 0; ind < size; ind++) {
        data[ind] = dataC[ind];
    }
    for(int ind = 0; ind < size-1; ind++) {
        int small = ind;
        for(int search = ind+1; search < size; search++) {
            if(data[search] < data[small]) {
                small = search;
            }
        }
        if(small != ind) {
            int temp = data[small];
            data[small] = data[ind];
            data[ind] = temp;
        }
    }
    return data;
}

//Reverses the array
int *reverse(const int *data, int size) {
    int *rev = new int[size];
    for(int ind = 0; ind < size; ind++) {
        rev[size-ind-1] = data[ind];
    }
    return rev;
}

//Prints the array
void prntDat(const int *data,int size) {
    for(int ind = 0; ind < size-1; ind++) {
        cout << data[ind] << " ";
    }
    cout << data[size-1];
}
/* 
 * File:   main.cpp
 * Author: Matthew Madrigal
 * Created on September 21st 2025, 6:40pm
 * Purpose:  Summing, Finding the Max and Min of an integer array
 * Note:  Look at the output for the format for print
 */

//System Libraries Here
#include <iostream>//cin,cout
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables

//Function Prototypes Here
void read(int [],int);
int  stat(const int [],int,int &,int &);
void print(const int [],int,int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;
    int array[SIZE];
    int sizeIn,sum,min,max;
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of integers find sum/min/max"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of integers
    cout<<"Now read the Array"<<endl;
    read(array,sizeIn);//Read in the array of integers
    
    //Find the sum, max, and min
    sum=stat(array,sizeIn,max,min);//Output the sum, max and min
    
    //Print the results
    print(array,sizeIn,sum,max,min);//print the array, sum, max and min

    //Exit
    return 0;
}

void read(int nums[], int size) {
    for(int index = 0; index < size; index++) {
        cin >> nums[index];
    }
}

//Gets sum of all numbers and gets the largest and smallest number
int stat(const int nums[], int size, int &max, int &min) {
    int sum = 0;
    min = nums[0]; //Assumes the first will be the smallest
    max = nums[0]; //Assumes the first will be the largest
    //Goes through each element, adds it to the sum, and then checks if its smaller or larger than the smallest or largest found
    for(int index = 0; index < size; index++) {
        sum += nums[index];
        if(nums[index] > max) {
            max = nums[index];
        }
        if(nums[index] < min) {
            min = nums[index];
        }
    }
    return sum;
}

//Prints results
void print(const int nums[], int size, int sum, int max, int min) {
    for(int index = 0; index < size; index++) {
        cout << "a[" << index << "] = " << nums[index] << endl;
    }
    cout << "Min  = " << min << endl;
    cout << "Max  = " << max << endl;
    cout << "Sum  = " << sum << endl;
}
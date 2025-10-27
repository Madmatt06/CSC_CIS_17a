/* 
 * File:   main.cpp
 * Author: Matthew Madrigal
 * Created on September 21st 2025, 7:30pm
 * Purpose:  Even, Odd Vectors and Array Columns Even, Odd
 * Note:  Check out content of Sample conditions in Hacker Rank
 * Input size of integer array, then array, output columns of Even, Odd
 * Vectors then Even, Odd 2-D Array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <vector>  //vectors<>
#include <iomanip> //Format setw(),right
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=2;//Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int> &, vector<int> &);
void copy(vector<int>, vector<int>,int [][COLMAX]);
void prntVec(vector<int>, vector<int>,int);//int n is the format setw(n)
void prntAry(const int [][COLMAX],int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //No more than 80 rows
    int array[ROW][COLMAX];     //Really, just an 80x2 array, even vs. odd
    vector<int> even(0),odd(0); //Declare even,odd vectors
    
    //Input data and place even in one vector odd in the other
    read(even,odd);
    
    //Now output the content of the vectors
    //          setw(10)
    prntVec(even,odd,10);//Input even, odd vectors with setw(10);
    
    //Copy the vectors into the 2 dimensional array
    copy(even,odd,array);
    
    //Now output the content of the array
    //                              setw(10)
    prntAry(array,even.size(),odd.size(),10);//Same format as even/odd vectors
    
    //Exit
    return 0;
}
//Gets input from user
void read(vector<int> &even, vector<int> &odd) {
    int size;
    cout << "Input the number of integers to input." << endl;
    cin >> size;
    cout << "Input each number." << endl;
    //Puts user input into even and odd vectors
    for(int index = 0; index < size; index++) {
        int num;
        cin >> num;
        if(num%2 != 0) { //Checks if number is odd
            odd.push_back(num);
        } else {
            even.push_back(num);
        }
    }
}
//Copies the vectors into a single array
void copy(vector<int> even, vector<int> odd, int nums[][COLMAX]) {
    for(int index = 0; index < even.size(); index++) {
        nums[index][0] = even[index]; //Even is first column
    }
    for(int index = 0; index < odd.size(); index++) {
        nums[index][1] = odd[index]; //Odd is second column
    }
}

void prntVec(vector<int> even, vector<int> odd,int format) {
    cout << setw(format) << "Vector" << setw(format) << "Even" << setw(format) << "Odd" << endl;
    int max = even.size(); //Used to print enough lines to fit largest vector
    if(max < odd.size()) {
        max = odd.size();
    }
    for(int index = 0; index < max; index++) {
        //The if statements prints " " for the even or odd column if there are no more
        cout << setw(format*2);
        if(even.size() > index) {
            cout << even[index];
        } else {
            cout << " ";
        }
        cout << setw(format); 
        if(odd.size() > index) {
            cout << odd[index];
        } else {
            cout << " ";
        }
        cout << endl;
    }
}

void prntAry(const int nums[][COLMAX],int evenSize,int oddSize,int format) {
    cout << setw(format) << "Array" << setw(format) << "Even" << setw(format) << "Odd" << endl;
    int max = evenSize; //Used to print enough lines to fit largest column of the array
    if(max < oddSize) {
        max = oddSize;
    }
    for(int index = 0; index < max; index++) {
        //The if statements prints " " for the even or odd column if there are no more
        cout << setw(format*2);
        if(evenSize > index) {
            cout << nums[index][0];
        } else {
            cout << " ";
        }
        cout << setw(format); 
        if(oddSize > index) {
            cout << nums[index][1];
        } else {
            cout << " ";
        }
        cout << endl;
    }
}
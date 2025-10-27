/* 
 * File:   main.cpp
 * Author: Matthew Madrigal
 * Created on September 21st, 7:40pm
 * Purpose:  Sum Rows, Sum Columns, Grand Sum of an integer array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <iomanip> //setw(10)
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;  //Max Columns much larger than needed.

//Function Prototypes Here
void read(int [][COLMAX],int &,int &);//Prompt for size then table
void sum(const int [][COLMAX],int,int,int[][COLMAX]);//Sum rows,col,grand total
void print(const int [][COLMAX],int,int,int);//Either table can be printed

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //Max Rows much larger than needed
    int array[ROW][COLMAX]={};  //Declare original array
    int augAry[ROW][COLMAX]={}; //Actual augmented table row+1, col+1
    int row,col;                
    
    //Input the original table
    read(array,row,col);
    
    //Augment the original table by the sums
    sum(array,row,col,augAry);
    
    //Output the original array
    cout<<endl<<"The Original Array"<<endl;
    print(array,row,col,10);//setw(10)
    
    //Output the augmented array
    cout<<endl<<"The Augmented Array"<<endl;
    print(augAry,row+1,col+1,10);//setw(10)
    
    //Exit
    return 0;
}

void read(int table[][COLMAX],int &row,int &col) {
    cout << "Input a table and output the Augment row,col and total sums." << endl;
    cout << "First input the number of rows and cols. <20 for each" << endl;
    cin >> row;
    cin >> col;
    //Gets the user input and puts them in the correct places.
    cout << "Now input the table." << endl;
    for(int rIndex = 0; rIndex < row; rIndex++) {
        for(int cIndex = 0; cIndex < col; cIndex++) {
            cin >> table[rIndex][cIndex];
        }
    }
}
void sum(const int table[][COLMAX],int row,int col,int tAug[][COLMAX]) {
    //Calculates the sum of the rows and puts it to the right.
    for(int rIndex = 0; rIndex < row; rIndex++) {
        int sum = 0;
        for(int cIndex = 0; cIndex < col; cIndex++) {
            tAug[rIndex][cIndex] = table[rIndex][cIndex];
            sum += tAug[rIndex][cIndex];
        }
        tAug[rIndex][col] = sum;
    }
    //Calculates the sum of the columns and puts it below. Also calculates the sum of the sum of rows.
    for(int cIndex = 0; cIndex < col+1; cIndex++) {
        int sum = 0;
        for(int rIndex = 0; rIndex < row; rIndex++) {
            sum += tAug[rIndex][cIndex];
        }
        tAug[row][cIndex] = sum;
    }
}
//Prints the table
void print(const int table[][COLMAX],int row,int col,int format) {
    for(int rIndex = 0; rIndex < row; rIndex++) {
        for(int cIndex = 0; cIndex < col; cIndex++) {
            cout << setw(format) << table[rIndex][cIndex];
        }
        cout << endl;
    }
}
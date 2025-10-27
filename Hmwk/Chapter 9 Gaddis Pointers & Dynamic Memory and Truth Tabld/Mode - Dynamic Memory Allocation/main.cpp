/* 
 * File:   main.cpp
 * Author: Matthew Madrigal
 * Created on September 28th, 2025, 4:45 PM
 */

//Libraries
#include <cstdlib>//Random number seed
#include <iostream>//I/O Library
#include <cmath>   //Math Library
using namespace std;

//No Global Constants

//Function Prototypes
int *fillAry(int,int);      //Fill the Array
void prntAry(int *,int,int);//Print the Array
void prntMod(int *);        //Print the mode set
void swap(int *,int *);     //Swap
void minPos(int *,int,int); //Find min Position
void mrkSort(int *,int);    //Mark Sort
int *copy(const int *,int); //Copy the Array
void shuffle(int *,int,int);//Shuffle the Array
unsigned int GRB();         //Generate Random Bit
void GR(unsigned int&);     //Generate Random Number
int *mode(const int *,int); //Find the mode set

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables and fill
    int arySize,//The array/set size
         modNum,//Unique numbers in the array
           *ary;//Pointer to the array
    
    //Input the number of unique numbers
    //and size of the array
    cout<<"The program finds the mode of a set"<<endl;
    cout<<"Input the size of the array and ";
    cout<<"quantity of unique numbers"<<endl;
    cin>>arySize>>modNum;
    ary=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"The Array before shuffling"<<endl;
    prntAry(ary,arySize,modNum);
    
    //Shuffle the Array 7 times
    shuffle(ary,arySize,7);
    
    //Calculate the mode array
    int *modeAry=mode(ary,arySize);
    
    //Print the initial array
    cout<<"The Array after shuffling"<<endl;
    prntAry(ary,arySize,modNum);
    
    //Print the modal information of the array
    cout<<"The Modal Information"<<endl;
    prntMod(modeAry);
    
    //Delete allocated memory
    delete []ary;
    delete []modeAry;
    
    //Exit stage right
    return 0;
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    int *b=new int[n];
    //Fill with passed array
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prntMod(int *ary){
    cout<<"The number of modes = "<<
            ary[0]<<endl;
    cout<<"The max Frequency = "<<
            ary[1]<<endl;
    if(ary[0]==0){
        cout<<"The mode set = {null}"<<endl;
        return;
    }
    cout<<"The mode set = {";
    for(int i=2;i<ary[0]+1;i++){
        cout<<ary[i]<<",";
    }
    cout<<ary[ary[0]+1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        minPos(array,n,i);
    }
}

void minPos(int *array,int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(*(array+pos)>*(array+i))
            swap(array+pos,array+i);
    }
}

void swap(int *a,int *b){
    //Swap in place
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}

void prntAry(int *array,int n,int perLine){
    //Output the array
    for(int i=0;i<n;i++){
        cout<<*(array+i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *fillAry(int n, int modNum){
    //Allocate memory
    int *array=new int[n];
    
    //Fill the array with 2 digit numbers
    for(int i=0;i<n;i++){
        *(array+i)=i%modNum;
        //*(array+i)=rand()%modNum;
    }
    
    //Exit function
    return array;
}

void shuffle(int *a,int n,int nShuf){
    unsigned int temp;
    for(int shuf=1;shuf<=nShuf;shuf++){
        for(int i=0;i<n;i++){
            GR(temp);
            temp%=n;
            if(i!=temp)swap(a[i],a[temp]);
        }
    }
}

unsigned int GRB(){
    static unsigned int seed=0;
    seed += (seed * seed) | 5;
    return seed & 0x80000000;
}
 
void GR(unsigned int& value){
    value=0;
    const unsigned int numBits = sizeof(int) * 8;
    unsigned int* dataPointer = (unsigned int *)&value;
    for (unsigned int index = 0; index < numBits; ++index)
    {
        if(GRB()) {
            unsigned int pointerIndex = index / 32;
            unsigned int mask = 1 << index % 32;
            dataPointer[pointerIndex] |= mask;
        }
    }
}

//This just a stub.  You are to fill in the correct solution
int *mode(const int *array,int arySize){
    //Copy the array
    int *ary=copy(array,arySize);
    //Sort the copy
    mrkSort(ary,arySize);
    //Find the max Frequency
    int max = 1;
    int curr = 1;
    for(int i = 1; i < arySize; i++) {
        if(ary[i-1] == ary[i]) {
            curr++; //Counts up frequencies until it finds a non matching pair.
        } else {
            if(max < curr) {
                max = curr;
            }
            curr = 1;
        }
    }
    //Find the number of modes
    curr = 1;
    int nummode = 0;
    for(int i = 1; i < arySize; i++) {
        if(ary[i-1] == ary[i]) {
            curr++;
            if(curr == max) {   //Modes will have the same frequency as the max
                nummode++; 
                curr = 1;
            }
        } else {
            curr = 1;
        }
        
    }
    //Allocate the mode array
    //Again this is just a stub.
    int nmodes=nummode;
    int *modeAry=new int[nmodes+2];
    modeAry[0]=nummode; //Returns number of modes
    modeAry[1]=max;     //Returns max found Frequency
    
    int modeind = 0;    //Keeps track of where in modeAry we are
    //Fill the mode array
    for(int i = 1; i < arySize; i++) {
        if(ary[i-1] == ary[i]) {
            curr++;
            if(curr == max) {
                modeAry[modeind+2] = ary[i]; //First 2 is information that was written before.
                modeind++;
                curr = 1;
            }
        } else {
            curr = 1;
        }
        
    }
    //Delete the allocated copy and return
    delete []ary;
    return modeAry;
}
/* 
 * Note:  This time you create the strcmp() function that takes into
 * account the new sort order.
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int,const char[],const char[]);//Sort by row using strcmp();
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array
//int strcmp(char a[],char b[],char replace[],char with[]){
int strcmp(char [],char [],const char [],const char []);//Replace sort order

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    char replace[COLMAX],with[COLMAX];//New sort order
    
    //Input the new sort order then sort
    cout<<"Modify the sort order by swapping these characters."<<endl;
    cin>>replace;
    cout<<"With the following characters"<<endl;
    cin>>with;
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    //if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn,replace,with);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
        
    //Exit
    return 0;
}
//Reads the input and puts it in an array
int read(char array[][COLMAX], int &rows) {
    int colMax = 0; //Keeps track of the largest string of text
    int index = 0;
    //Keeps taking data in until there is no more
    while(cin >> array[index]) {
        int col = strlen(array[index]);
        if(colMax < col) {
            colMax = col;
        }
        index++;
    }
    rows = index;
    return colMax;
}

//Sorts the arrays
void sort(char array[][COLMAX], int rows, int cols, const char replace[], const char with[]) {
    for(int row = 0; row < rows; row++) {
        for(int cRow = row + 1; cRow < rows; cRow++) {
            if(strcmp(array[row], array[cRow], replace, with) > 0) {
                //Swaps the strings
                char temp[COLMAX];
                strcpy(temp, array[row]);
                strcpy(array[row], array[cRow]);
                strcpy(array[cRow], temp);
            }
        }
    }
}

//Prints all of the elements in the array
void print(const char array[][COLMAX],int rows,int cols) {
    for(int index = 0; index < rows; index++) {
        cout << array[index] << endl;
    }
}
int strcmp(char a[],char b[],const char replace[],const char with[]) {
    int index = 0;
    int replaceSize = strlen(replace);
    int withSize = strlen(with);
    int aSize = strlen(a);
    int bSize = strlen(b);
    //Goes through each character and checks if they have a replacment. If they do, use that instead. Then compares. If they different, return the difference.
    while (index < aSize && index < bSize) {
        char ca;
        bool found = false;
        int sIndex = 0;
        //Checks for replacements
        while (sIndex < replaceSize && sIndex < withSize) {
            if (a[index] == replace[sIndex]) { //If found, uses that instead of original char
                found = true;
                ca = with[sIndex];
                break;
            }
            sIndex++;
        }
        if(!found) {
            ca = a[index]; //If no replacement found, use original char
        }
        char cb;
        found = false;
        sIndex = 0;
        //Checks for replacements
        while (sIndex < replaceSize && sIndex < withSize) {
            if (b[index] == replace[sIndex]) { //If found, uses that instead of original char
                found = true;
                cb = with[sIndex];
                break;
            }
            sIndex++;
        }
        if(!found) {
            cb = b[index]; //If no replacement found, use original char
        }
        if (ca != cb) {
            return ca - cb; //If difference found, return difference.
        }
        ++index;
    }
    //If no difference was found in existing character, return the size difference since the shorter one should go first..
    return aSize - bSize;
}
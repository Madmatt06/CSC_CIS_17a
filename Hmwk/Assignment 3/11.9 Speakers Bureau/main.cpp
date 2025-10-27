/* 
 * File:   main.cpp
 * Author: Matthew Madrigal
 * Created on October 21st, 2025, 10:30 pm,
 * Purpose:  To store data about speakers using structures
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - Math/Science/Conversions only

//Structures
struct Speaker {
    string name;
    string telNum;  // Telephone number
    string spktop;  // Speaking topic
    float fee;      // Fee required
};

//Function Prototypes
void printData(const Speaker &);
void remove(Speaker [], int &, int);
void edit(Speaker &);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    const int size = 10;
    int num = 0;
    bool running;
    Speaker speakers[size];
    //Initialize Variables
    running = true;
    
    while(running) {
        //The Process -> Map Inputs to Outputs
        // Gets the user selection after printing the options
        cout << "0. View speakers" << endl
             << "1. Add speaker" << endl
             << "2. Remove speaker" << endl
             << "3. Edit Speaker" << endl
             << "4. Quit" << endl;
        int choice;
        cin >> choice;
        if(choice < 0 || choice > 4) {
            cout << "Invalid selection" << endl;
        } else {
            int index;
            switch(choice) {
                // Prints all of the speakers if any are saved or lets the user know there is nothing to print
                case 0:
                if(num <= 0) {
                    cout << "No speakers are currently saved." << endl;
                    break;
                }
                cout << endl;
                for(int i = 0; i < num; i++) {
                    cout << i << "." <<  endl;
                    printData(speakers[i]);
                    cout << endl << endl;
                }
                break;
                
                // Checks if it can add a speaker. Adds one if thats true using edit function after clearing the slot.
                case 1:
                if(num >= size) {
                    cout << "You have reached the maximum allowed speakers of " << size;
                    break;
                }
                speakers[num].fee = 0;
                speakers[num].name = "";
                speakers[num].spktop = "";
                speakers[num].telNum = "";
                edit(speakers[num]);
                num++;
                break;

                // Gets the index of the speaker to remove and checks if it exists. Removes it if true
                case 2:
                if(num <= 0) {
                    cout << "There are no speakers to remove" << endl;
                    break;
                }
                cout << "Enter a speaker's index to remove: ";
                cin >> index;
                if(index >= num || index < 0) {
                    cout << "Invalid selection" << endl;
                    break;
                }
                remove(speakers, num, index);
                break;

                // Gets the index of the speaker to edit and checks if it exists. Calls the edit function if true
                case 3:
                if(num <= 0) {
                    cout << "There are no speakers to edit" << endl;
                    break;
                }
                cout << "Enter a speakers index to edit: ";
                index = 0;
                cin >> index;
                if(index >= num || index < 0) {
                    cout << "Invalid selection" << endl;
                    break;
                }
                edit(speakers[index]);
                break;
                case 4:
                running = false;
            }
        }
    
        //Display Inputs/Outputs

    }

    //Exit the Program
    return 0;
}

// Prints the speaker data with some formatting
void printData(const Speaker &speaker) {
    cout << "Name: " << speaker.name << endl <<
            "Telephone Number: " << speaker.telNum << endl <<
            "Speaking Topic: " << speaker.spktop << endl <<
            "Fee: " << speaker.fee;
}

// Removes the speaker and shifts anything if neccesary to the left
void remove(Speaker speakers[], int &size, int index) {
    for(int i = index; i < size-1; i++) {
        speakers[i].name = speakers[i+1].name;
        speakers[i].telNum = speakers[i+1].telNum;
        speakers[i].spktop = speakers[i+1].spktop;
        speakers[i].fee = speakers[i+1].fee;
    }
    size--;
}

// Edits the speaker by displaying the current data and then asking what to change it to
void edit(Speaker &speaker) {
    cout << "Speaker currently has name \"" << speaker.name << "\"" << endl;
    cout << "Enter a new name: ";
    cin.ignore();
    // Makes sure the input is not empty
    do {
        getline(cin, speaker.name);
        if(speaker.name == "") {
            cout << "Enter a new name: ";
        }
    } while(speaker.name == "");

    cout << "Speaker currently has telephone number \"" << speaker.telNum << "\"" << endl;
    cout << "Enter a new telephone number: ";
    // Makes sure the input is not empty
    do {
        getline(cin, speaker.telNum);
        if(speaker.telNum == "") {
            cout << "Enter a new telephone number: ";
        }
    } while(speaker.telNum == "");

    cout << "Speaker currently has speaking topic \"" << speaker.spktop << "\"" << endl;
    cout << "Enter a new speaking topic: ";
    // Makes sure the input is not empty
    do {
        getline(cin, speaker.spktop);
        if(speaker.spktop == "") {
            cout << "Enter a new speaking topic: ";
        }
    } while(speaker.spktop == "");

    cout << "Speaker currently has fee of " << speaker.fee << endl;
    cout << "Enter a new fee: ";
    // Makes sure the input is not empty
    do {
        cin >> speaker.fee;
        if(speaker.fee < 0) {
            cout << "Enter a new fee: ";
        }
    } while(speaker.fee < 0);
}
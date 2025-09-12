/* 
 * File:   TonyGaddis_9_5_11_population.cpp
 * Author: Matthew Madrigal
 * Created on September 11, 2025, 8:08 pm,
 * Purpose:  To predict the size of a population of organisms. Prints their population each day
 */

//System Libraries
#include <iostream>
using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    const string getPop = "Enter a starting population size (2+): ";
    const string getPerc = "Enter the percent increase per day (0%+): ";
    const string getDays = "Enter the number of days (1+): ";
    const string invEnt = "Invalid entry";  //Message is displayed if number supplied is out of range
    const int minPop = 2;
    const int minPerc = 0;
    const int minDays = 1;
    int pop, days; //pop is the starting population. days is the number of times to increase the population.
    int increase;       //Used to store increase in population
    double perc, percDec;     //perc is the increase of population every day in %. perDec is used to save percentage as a decimal for easier math
    //Initialize Variables
    pop = -1;
    perc = -1;
    days = -1;
    while(pop < minPop) {
        cout << getPop;
        cin >> pop;
        if(pop < minPop) {
            cout << invEnt << endl;
        }
    }
    while(perc < minPerc) {
        cout << getPerc;
        cin >> perc;
        if(perc < minPerc) {
            cout << invEnt << endl;
        }
    }
    while(days < minDays) {
        cout << getDays;
        cin >> days;
        if(days < minDays) {
            cout << invEnt << endl;
        }
    }
    //The Process -> Map Inputs to Outputs
    percDec = perc/100;
    
    //Display Inputs/Outputs
    cout << "Day 0: " << pop << endl;
    for(int day = 0; day < days; day++) {
        increase = pop*percDec;
        pop += increase;
        cout << "Day " << day+1 << ": " << pop << endl;
    }

    //Exit the Program
    return 0;
}
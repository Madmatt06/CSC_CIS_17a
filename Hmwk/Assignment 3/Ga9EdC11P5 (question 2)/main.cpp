/* 
 * File: main.cpp
 * Author: Matthew Madrigal
 * Created on: October 21st, 2025, 10:00 pm
 * Purpose: To demonstrate use of a structure to store weather statistics and generate data
 */

#include <iostream>
#include <cmath>

using namespace std;

// Structures
struct Month {
    float totR; // Total rainfall
    int tmpH; // Highest Temperature
    int tmpL; // Lowest Temperature
    int tmpA; // Average Temperature
};

//Enums
enum Months {JANUARY, FEBURARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};

int main(){
	//your code here
	//Variables and constants
	const Months endMon = JULY;
	Month months[endMon];
	
	//Gets data
	for(int i = JANUARY; i < endMon; i++) {
        cout << "Enter the total rainfall for the month:" << endl;
	    cin >> months[i].totR;
	    
	    // Input validation -100 to 140 only for highest temperature
	    cout << "Enter the high temp:" << endl;
	    do {
	        cin >> months[i].tmpH;
	        if(months[i].tmpH < -100 || months[i].tmpH > 140) {
	            cout << "Invalid Input.";
	        }
	    } while(months[i].tmpH < -100 || months[i].tmpH > 140);
	    
	    
	    // Input validation -100 to 140 only for lowest temperature
	    cout << "Enter the low temp:" << endl;
	    do {
	        cin >> months[i].tmpL;
	        if(months[i].tmpL < -100 || months[i].tmpL > 140) {
	            cout << "Invalid Input.";
	        }
	    } while(months[i].tmpL < -100 || months[i].tmpL > 140);
	    
	    
	    // Calculates average
	    months[i].tmpA = (months[i].tmpH + months[i].tmpL) / 2;
	}
	
	// Calculates Monthly Average Rainfall
	float avRain = 0;
	for(int i = 0; i < endMon; i++) {
	    avRain += months[i].totR;
	}
	
	// Rounds to the hundreth place
	avRain /= endMon*1.0;
	avRain *= 100;
	avRain = round(avRain);
	avRain /= 100;
	
	// Finds lowest temperature
	int lTemp = months[0].tmpL;
	for(int i = JANUARY; i < endMon; i++) {
	    if(lTemp > months[i].tmpL) {
	        lTemp = months[i].tmpL;
	    }
	}
	
	// Finds highest temperature
	int hTemp = months[0].tmpH;
	for(int i = JANUARY; i < endMon; i++) {
	    if(hTemp < months[i].tmpH) {
	        hTemp = months[i].tmpH;
	    }
	}
	
	// Finds average temperature
	float aveTmp = 0;
	for(int i = JANUARY; i < endMon; i++) {
	    aveTmp += months[i].tmpL;
	    aveTmp += months[i].tmpH;
	}
	aveTmp /= endMon*2;
	
	// Rounds to tenth place
	aveTmp *= 10;
	aveTmp = round(aveTmp);
	aveTmp /= 10;
	
	// Outputs results
	cout << "Average monthly rainfall:" << avRain << endl;
	cout << "High Temp:" << hTemp << endl;
	cout << "Low Temp:" << lTemp << endl;
	cout << "Average Temp:" << aveTmp;
	
	return 0;
}
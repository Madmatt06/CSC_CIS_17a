/* 
 * File: main.cpp
 * Author: Matthew Madrigal
 * Created on: October 21st, 2025, 7:16pm
 * Purpose: To demonstrate use of a structure to store weather statistics and generate data
 */

#include <iostream>
#include <cmath>

using namespace std;

struct Month {
    string name;
    int totR; // Total rainfall
    int tmpH; // Highest Temperature
    int tmpL; // Lowest Temperature
    int tmpA; // Average Temperature
};

int main(){
	//your code here
	//Variables and constants
	const int numMon = 12;
	Month months[numMon];
	
	//Gets data
	for(int i = 0; i < numMon; i++) {
	    cin >> months[i].name;
	    cin >> months[i].totR;
	    
	    // Input validation -100 to 140 only for lowest temperature
	    do {
	        cin >> months[i].tmpL;
	        if(months[i].tmpL < -100 || months[i].tmpL > 140) {
	            cout << "Invalid Input.";
	        }
	    } while(months[i].tmpL < -100 || months[i].tmpL > 140);
	    
	    // Input validation -100 to 140 only for highest temperature
	    do {
	        cin >> months[i].tmpH;
	        if(months[i].tmpH < -100 || months[i].tmpH > 140) {
	            cout << "Invalid Input.";
	        }
	    } while(months[i].tmpH < -100 || months[i].tmpH > 140);
	    
	    // Calculates average
	    months[i].tmpA = (months[i].tmpH + months[i].tmpL) / 2;
	}
	
	// Calculates Monthly Average Rainfall
	float avRain = 0;
	for(int i = 0; i < numMon; i++) {
	    avRain += months[i].totR;
	}
	
	// Rounds to the tenth place
	avRain /= numMon*1.0;
	avRain *= 10;
	avRain = round(avRain);
	avRain /= 10;
	
	// Finds lowest temperature
	int lTemp = months[0].tmpL;
	string lMon = months[0].name;
	for(int i = 0; i < numMon; i++) {
	    if(lTemp > months[i].tmpL) {
	        lTemp = months[i].tmpL;
	        lMon = months[i].name;
	    }
	}
	
	// Finds highest temperature
	int hTemp = months[0].tmpH;
	string hMon = months[0].name;
	for(int i = 0; i < numMon; i++) {
	    if(hTemp < months[i].tmpH) {
	        hTemp = months[i].tmpH;
	        hMon = months[i].name;
	    }
	}
	
	// Finds average temperature
	float aveTmp = 0;
	for(int i = 0; i < numMon; i++) {
	    aveTmp += months[i].tmpL;
	    aveTmp += months[i].tmpH;
	}
	aveTmp /= numMon*2;
	
	// Rounds to ones place
	int aveTmpI = round(aveTmp);
	
	// Outputs results
	cout << "Average Rainfall " << avRain << " inches/month" << endl;
	cout << "Lowest  Temperature " << lMon << "  " << lTemp << " Degrees Fahrenheit" << endl;
	cout << "Highest Temperature " << hMon << "  " << hTemp << " Degrees Fahrenheit" << endl;
	cout << "Average Temperature for the year " << aveTmpI << " Degrees Fahrenheit" << endl;
	
	return 0;
}
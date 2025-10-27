/* 
 * File: main.cpp
 * Author: Matthew Madrigal
 * Created on: October 21st, 2025, 9:04 pm
 * Purpose: To demonstrate use of a structure to store drink data
 */

#include <iostream>
#include <iomanip>

using namespace std;

// Structures
struct Drink {
    string name;
    int cost;   // Stored as cents instead of dollars
    int stock;
};

int main(){
	//your code here
	// Variables and constants
	const int size = 5;
	Drink drinks[size];
	const int nSize = 11; // Setw size for name
	const int pSize = 4; // Setw size for price
	
	// Initialize Variables
	// Sets up all the drinks
	drinks[0].name = "Cola";
	drinks[0].cost = 75;
	drinks[0].stock = 20;
	drinks[1].name = "Root Beer";
	drinks[1].cost = 75;
	drinks[1].stock = 20;
	drinks[2].name = "Lemon-Lime";
	drinks[2].cost = 75;
	drinks[2].stock = 20;
	drinks[3].name = "Grape Soda";
	drinks[3].cost = 80;
	drinks[3].stock = 20;
	drinks[4].name = "Cream Soda";
	drinks[4].cost = 80;
	drinks[4].stock = 20;
	
	bool running = true;
	int earning = 0;
	//Main loop
	while(running) {
	    
	    // Prints options for users
	    for(int i = 0; i < size; i++) {
	        cout << left << setw(nSize) << drinks[i].name << setw(pSize) << drinks[i].cost << drinks[i].stock << endl;
	    }
	    cout << "Quit" << endl;
	    
	    // Gets user choice
	    string choice;
	    getline(cin, choice);
	    
	    // Quits if the user wants to exit
	    if(choice == "Quit") {
	        cout << earning << endl;
	        running = false;
	    } else {
	        // Gets the amount the user wants to pay
	        int payment = -1;
	        cin >> payment;
	        cin.ignore();
	        
	        // Bounds check
	        if(payment < 0 || payment > 100) {
	            cout << "Invalid input" << endl;
	        } else {
	            // Tries to find the drink the user wants and checks if they can purchase it.
	            for(int i = 0; i < size; i++) {
	                if(drinks[i].name == choice) {
	                    // Checks to see if drink is even in stock
	                    if(drinks[i].stock <= 0) {
	                        cout << "Sold out" << endl;
	                        break;
	                    }
	                    // It was never mentioned to handle this case but it just makes sense to do check if the user can afford it
	                    if(drinks[i].cost > payment) {
	                        cout << "Not enought money" << endl;
	                        break;
	                    }
	                    // Prints change, adds to earnings, and removes one from stock
	                    cout << payment - drinks[i].cost << endl;
	                    earning += drinks[i].cost;
	                    drinks[i].stock--;
	                    break;
	                }
	            }
	        }
	    }
	}
	return 0;
}
/* 
 * File: main.cpp
 * Author: Matthew Madrigal
 * Created on: October 21st, 2025, 7:19pm
 * Purpose: To demonstrate use of a structure to store data for movies
 */

#include <iostream>
#include <iomanip>

using namespace std;

// Structure definition
struct Movie {
    string title;   // Movie Title
    string dir;     // Director
    int year;
    int length;     //Running time (minutes)
};

// Function prototypes
void printMovie(const Movie &);

int main(){
	//your code here
	// Constants and variables
	Movie *movies;
	int size;
	
	// Introduction
	cout << "This program reviews structures" << endl;
	cout << "Input how many movies, the Title of the Movie, Director, Year Released, and the Running Time in (minutes)." << endl;
	
	// Gets number of movies to store
	cin >> size;
	cin.ignore();
	
	// Creates dynamic array with correct size
	movies = new Movie[size];
	
	// Gets movie data
	for(int i = 0; i < size; i++) {
	    getline(cin, movies[i].title);
	    getline(cin, movies[i].dir);
	    cin >> movies[i].year;
	    cin >> movies[i].length;
	    cin.ignore();
	}
	
	// Prints movie data
	for(int i = 0; i < size; i++) {
	    printMovie(movies[i]);
	}
	
	delete []movies;
	
	return 0;
}

void printMovie(const Movie &movie) {
    const int length = 11; // Formatting settings
    // Formatting
    cout << endl;
    // Movie details
    cout << setw(length) << left << "Title:" << movie.title << endl;
    cout << setw(length) << left << "Director:" << movie.dir << endl;
    cout << setw(length) << left << "Year:" << movie.year << endl;
    cout << setw(length) << left << "Length:" << movie.length << endl;
}


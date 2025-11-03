/* 
 * File:   main.cpp
 * Author: Matthew Madrigal
 * Created on November 2nd, 2025, 11:41 am,
 * Purpose:  To determine the prime factors of a number.
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "prime.h"
#include "primes.h"
//Global Constants - Math/Science/Conversions only

//Function Prototypes
bool valNum(string, bool); //A function I have used in multiple questions to validate the user input
bool isPrime(int); //Determine if the number is Prime
int power(int, int&); //What power is this factor and remove from n
int nPrimes(int); //How many Primes
void cleanUp(Primes *); //Clean it all up
Primes *factor(int); //Factor the number into it’s Primes
void prtPrms(const Primes *); //Print the prime factors

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    unsigned short int n;
    string input;
    bool valid;
    //Initialize Variables
    // Gets a number and makes sure its valid
    do {
        cout << "Enter a number [2,65000]: ";
        cin >> input;
        valid = valNum(input, false);
        if(valid) {
            n = stoi(input);
            valid = (n >= 2 && n <= 65000);
        }
    } while(!valid);
    
    //The Process -> Map Inputs to Outputs
    Primes *primes = factor(n);
    
    //Display Inputs/Outputs
    prtPrms(primes);

    //Exit the Program
    cleanUp(primes);
    return 0;
}

bool isPrime(int num) {
    // Checks if a number is prime by dividing up to the square root (the other half doesn't matter, the first half relies on the second half.)
    if(num < 2) return false;
    int max = sqrt(num);
    for(int i = 2; i <= max; i++) {
        if(num%i == 0) return false;
    }
    return true;
}

int power(int div, int &num) {
    int power = 0;
    while(num % div == 0) {
        num /= div;
        power++;
    }
    return power;
}

int nPrimes(int n) {
    cout << "Obtained " << n << endl;
    int count = 0;
    for(int i = n; i >= 2; i--) {
        if(n % i == 0) {
            if(isPrime(i)) count++;
        }
    }
    return count;
}

void cleanUp(Primes *primes) {
    delete []primes->pStrAry;
    delete primes;
}

Primes *factor(int n) {
    Primes *primes = new Primes;
    primes->n = n;
    primes->nPrimes = nPrimes(n);
    primes->pStrAry = new Prime[primes->nPrimes];
    int prInd = 0;
    for(int i = n; i >= 2; i--) {
        if(n == 1) break;
        if(n % i == 0) {
            if(isPrime(i)) {
                primes->pStrAry[prInd].prime = i;
                primes->pStrAry[prInd].power = power(i, n);
                prInd++;
            }
        }
    }
    return primes;
}
void prtPrms(const Primes *primes) {
    cout << primes->n << " =";
    for(int i = primes->nPrimes - 1; i >= 0; i--) {
        cout << " " << primes->pStrAry[i].prime << "^" << static_cast<int>(primes->pStrAry[i].power);
    }
    cout << endl;
}

bool valNum(string input, bool zero) {
    bool isZero = true;
    if(input.length() > 0) {
        for(int i = 0; i < input.length(); i++) {
            if(!isdigit(input[i])) return false;
            if(input[i] != '0') isZero = false;
        }
    } else return false;
    return !isZero || zero;
}
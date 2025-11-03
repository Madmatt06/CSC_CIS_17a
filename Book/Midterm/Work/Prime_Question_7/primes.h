/* 
 * File:   primes.h
 * Author:  Matthew Madrigal
 * Purpose:  Primes structure specification
 */

#ifndef PRIMES_H
#define PRIMES_H
#include "prime.h"
using namespace std;
struct Primes{
    unsigned short n; //Number to factor into Primes
    unsigned char nPrimes; //Number of Primes
    Prime *pStrAry; //The Prime Structure Array
};
#endif
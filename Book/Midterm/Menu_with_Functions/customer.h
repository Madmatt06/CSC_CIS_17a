/* 
 * File:   customer.h
 * Author:  Matthew Madrigal
 * Purpose:  customer structure specification
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
using namespace std;
struct Customer {
    char accnum[6]; // +1 for null terminator
    string name;
    string addr;
    double bal;
    double *draw;
    double *deposit;
    int drSize;
    int deSize;
};
#endif
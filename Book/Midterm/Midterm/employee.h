/* 
 * File:   employee.h
 * Author:  Matthew Madrigal
 * Purpose:  employee structure specification
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;
struct Employee {
    string name;
    double hours;
    double rate;
    double amount;
};
#endif
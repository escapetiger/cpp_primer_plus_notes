/******************************************************************************
* File:             stringbad.cpp
*
* Author:           Joey Tsai  
* Created:          08/29/21 
* Description:      Stringbad class methods
*****************************************************************************/

#include <cstring>
#include "stringbad.h"
using std::cout;

// initializing static class member
int Stringbad::num_strings = 0;

// class methods
Stringbad::Stringbad()
{
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++");
    num_strings++;
    cout << num_strings << ": \"" << str
        << "\" object created\n"; // for you information
}

// construct Stringbad from C string
Stringbad::Stringbad(const char * s)
{
    len = std::strlen(s);                // set size
    str = new char[len + 1];             // allot storage
    std::strcpy(str, s);                 // initialize pointer
    num_strings++;
    cout << num_strings << ": \"" << str
        << "\" object created \n";
}

std::ostream & operator<<(std::ostream & os, const Stringbad & obj)
{
	return os;
}

Stringbad::~Stringbad()
{
    cout << "\"" << str << "\" object deleted, ";
    --num_strings; // required
    cout << num_strings << " left\n";
    delete [] str; // required
}


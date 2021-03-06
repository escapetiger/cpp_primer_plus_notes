/******************************************************************************
* File:             stringbad.h
*
* Author:           Joey Tsai  
* Created:          08/29/21 
* Description:      flawed string class definition
*****************************************************************************/

#ifndef STRINGBAD_H
#define STRINGBAD_H

#include <iostream>
#include <ostream>
class Stringbad
{
private:
    char * str;             // pointer to string
    int len;                // length of string
    static int num_strings; // number of objects

public:
    Stringbad(); // default constructor
    Stringbad(const char * s); // constructor
    virtual ~Stringbad(); // destructor
    // friend function
    friend std::ostream & operator<<(std::ostream & os, const Stringbad & obj);
};

#endif /* STRINGBAD_H */

/******************************************************************************
* File:             string1.h
*
* Author:           Joey Tsai
* Created:          08/29/21
* Description:      fixed and augmented string class definition
*****************************************************************************/

#ifndef STRING1_H
#define STRING1_H

#include <iostream>
using std::ostream;
using std::istream;
class String
{
private:
    char * str;                   // pointer to string
    int len;                      // length of string
    static int num_strings;       // number of objects
    static const int CINLIM = 80; // cin input limit
public:
    // constructors and other methods
    String();               // default constructor
    String(const char *); // constructor
    String(const String &); // copy constructor
    virtual ~String();      // destructor
    int length() const {return len; };
    // overloaded operator methods
    String & operator=(const String &);
    String & operator=(const char *);
    char & operator[](int i);
    const char & operator[](int i) const;
    // overloaded operator friends 
    friend bool operator<(const String & st1, const String & st2);
    friend bool operator>(const String & st1, const String & st2);
    friend bool operator==(const String & st1, const String & st2);
    friend std::ostream & operator<<(std::ostream & os, const String & st);
    friend std::istream & operator>>(std::istream & is, String & st);
    // static function
    static int HowMany();

};

#endif /* STRING1_H */

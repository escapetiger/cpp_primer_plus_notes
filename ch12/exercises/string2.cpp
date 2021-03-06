/******************************************************************************
* File:             string2.cpp
*
* Author:           Joey Tsai
* Created:          08/29/21
* Description:      String class methods
*****************************************************************************/

#include <cctype>
#include <cstring>
#include "string2.h"

// initializing static class member
int String::num_strings = 0;

// static method
int String::HowMany()
{
    return num_strings;
}

// class methods
String::String()
{
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}


String::String(const String & st)
{
    num_strings++;            // handle static member update
    len = st.len;             // same length
    str = new char[len + 1];  // allot space
    std::strcpy(str, st.str); // copy string to new location
}

String::String(const char * st)
{
    len = std::strlen(st);
    str = new char[len + 1];
    std::strcpy(str, st);
    num_strings++;
}

bool operator<(const String & st1, const String & st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

std::ostream & operator<<(std::ostream & os, const String & st)
{
    os << st.str;
    return os;
}

String & String::operator=(const String & st)
{
    if (this == &st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

String & String::operator=(const char * st)
{
    delete [] str;
    len = std::strlen(st);
    str = new char[len + 1];
    std::strcpy(str, st);
    return *this;
}

bool operator==(const String & st1, const String & st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

bool operator>(const String & st1, const String & st2)
{
    return st2 < st1;
}

std::istream & operator>>(std::istream & is, String & st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}

char & String::operator[](int i)
{
    return str[i];
}

const char & String::operator[](int i) const
{
    return str[i];
}


String & String::stringlow()
{
    for (int i = 0; i < len; ++i)
        str[i] = (char) std::tolower(str[i]);
    return *this;
}

String & String::stringup()
{
    for (int i = 0; i < len; ++i)
        str[i] = (char) std::toupper(str[i]);
    return *this;
}

String String::operator+(const String & obj) const
{
    String sum;
    sum.len = len + obj.len;
    sum.str = new char[sum.len + 1];
    std::strcpy(sum.str, str);
    std::strcpy(sum.str + len, obj.str);
    num_strings++;

    return sum;
}
String String::operator+(const char * s)
{
    String sum;
    sum.len = len + std::strlen(s);
    sum.str = new char[sum.len + 1];
    std::strcpy(sum.str, str);
    std::strcpy(sum.str + len, s);
    num_strings++;

    return sum;
}
String operator+(const char * s, const String & obj)
{
    String sum;
    sum.len = obj.len + std::strlen(s);
    sum.str = new char[sum.len + 1];
    std::strcpy(sum.str, s);
    std::strcpy(sum.str + std::strlen(s), obj.str);
    String::num_strings++;

    return sum;
}
int String::has(char c) const
{
    int ct = 0;
    for (int i = 0; i < len; ++i)
        if (str[i] == c)
            ++ct;

    return ct;
}

String::~String()
{
    --num_strings;
    delete [] str;
}

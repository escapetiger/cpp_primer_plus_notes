// person.cpp -- definitions of member functions in Person class

#include <iostream>
#include "person.h"

Person::Person()
{
}

Person::Person(const std::string & ln, const std::string & fn)
{
    lname = ln;
    fname = fn;
}

void Person::FormalShow() const
{
    std::cout << "Hello, " << lname << ", " << fname << std::endl;
}

void Person::show() const
{
    std::cout << "Hello, " << fname << " " << lname << std::endl;
}

Person::~Person()
{
}


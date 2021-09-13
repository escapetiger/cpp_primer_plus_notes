// plorg.cpp -- member functions of Plorg class
#include <exception>
#include <iostream>
#include <cstring>
#include "plorg.h"
Plorg::Plorg()
{
    std::strcpy(name_, "Plorga");
    CI_ = 0;
}

Plorg::Plorg(const char * name, int CI)
{
    if (std::strlen(name) > 19)
    {
        std::cerr << "The length of name should less than 19.";
        abort();
    }
    std::strcpy(name_, name);
    CI_ = CI;
}

void Plorg::reset(int CI)
{
    CI_ = CI;
}

void Plorg::show()
{
    std::cout << name_ << " " << CI_ << std::endl;
}

Plorg::~Plorg()
{
}

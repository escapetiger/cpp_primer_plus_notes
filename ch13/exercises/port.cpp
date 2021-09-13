/******************************************************************************
* File:             port.cpp
*
* Author:           Joey Tsai
* Created:          09/02/21
* Description:      Port class methods
*****************************************************************************/

#include "port.h"
#include <cstring>
Port::Port(const char * br, const char * st, int b)
{
    brand = new char[std::strlen(br) + 1];
    std::strcpy(brand, br);
    std::strcpy(style, st);
    bottles = b;
}

Port::Port(const Port & p)
{
    brand = new char[std::strlen(p.brand) + 1];
    std::strcpy(brand, p.brand);
    std::strcpy(style, p.style);
    bottles = p.bottles;
}

Port & Port::operator=(const Port & p)
{
    if (this == &p)
        return *this;
    delete [] brand;
    brand = new char[std::strlen(p.brand) + 1];
    std::strcpy(brand, p.brand);
    std::strcpy(style, p.style);
    bottles = p.bottles;
    return *this;
}

Port & Port::operator+=(int b)
{
    this->bottles += b;
    return *this;
}

Port & Port::operator-=(int b)
{
    if (this->bottles > 0)
        this->bottles -= b;
    else
        std::cout << "No bottles!" << std::endl;
    return *this;
}

void Port::Show() const
{
    if (brand == nullptr)
        std::cout << "No brand!" << std::endl;
    else
        std::cout << "Brand: " << brand << std::endl;
    std::cout << "Kind: " << style << std::endl;
    std::cout << "Bottles: " << bottles << std::endl;
}

std::ostream & operator<<(std::ostream & os, const Port & p)
{
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}

/******************************************************************************
* File:             cow.cpp
*
* Author:           Joey Tsai  
* Created:          08/30/21 
* Description:      member functions for Cow class
*****************************************************************************/

#include <iostream>
#include <cstring>
#include "cow.h"

Cow::Cow()
{
    std::strcpy(name, "");
    hobby = nullptr;
    weight = 0.0;
}

Cow::Cow(const Cow & c)
{
    std::strcpy(name, c.name);
    int len = std::strlen(c.hobby);
    hobby = new char[len + 1];
    std::strcpy(hobby, c.hobby);
    weight = c.weight;
}

Cow::Cow(const char * nm, const char * ho, double wt)
{
    std::strcpy(name, nm);
    int len = std::strlen(ho);
    hobby = new char[len + 1];
    std::strcpy(hobby, ho);
    weight = wt;
}

void Cow::ShowCow() const
{
    std::cout << "Name: " << name << std::endl ;
    std::cout << "Hobby: " << hobby << std::endl;
    std::cout << "Weight: " << weight << std::endl;
}

Cow & Cow::operator=(const Cow & c)
{
    std::strcpy(name, c.name);
    delete [] hobby;
    int len = std::strlen(c.hobby);
    hobby = new char[len + 1];
    std::strcpy(hobby, c.hobby);
    weight = c.weight;

	return *this;
}

Cow::~Cow()
{
    delete [] hobby;
}


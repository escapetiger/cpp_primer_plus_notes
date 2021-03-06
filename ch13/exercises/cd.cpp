/******************************************************************************
* File:             cd.cpp
*
* Author:           Joey Tsai
* Created:          09/02/21
* Description:      Cd class methods
*****************************************************************************/
#include "cd.h"
#include <iostream>
#include <cstring>

Cd::Cd()
{
    performers = nullptr;
    label = nullptr;
    selections = 0;
    playtime = 0.0;
}

Cd::Cd(const char * s1, const char * s2, int n, double x)
{
    performers = new char[std::strlen(s1) + 1];
    label = new char[std::strlen(s2) + 1];
    std::strcpy(performers, s1);
    std::strcpy(label, s2);
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd & d)
{
    performers = new char[std::strlen(d.performers) + 1];
    std::strcpy(performers, d.performers);
    label = new char[std::strlen(d.label) + 1];
    std::strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}

void Cd::Report() const
{
    if (performers == nullptr)
        std::cout << "No performers!" << std::endl;
    else
        std::cout << "Performers: " << performers << std::endl;

    if (label == nullptr)
        std::cout << "No label!" << std::endl;
    else
        std::cout << "Label: " << label << std::endl;

    std::cout << "Selections: " << selections << std::endl;
    std::cout << "Playtime: " << playtime << std::endl;
}

Cd & Cd::operator=(const Cd & d)
{
    if (this == &d)
        return *this;
    delete [] performers;
    delete [] label;
    performers = new char[std::strlen(d.performers) + 1];
    std::strcpy(performers, d.performers);
    label = new char[std::strlen(d.label) + 1];
    std::strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

Cd::~Cd()
{
    delete [] performers;
    delete [] label;
}

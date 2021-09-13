/******************************************************************************
* File:             classic.cpp
*
* Author:           Joey Tsai
* Created:          09/02/21
* Description:      Classic class methods
*****************************************************************************/

#include <iostream>
#include "classic.h"
#include <cstring>
Classic::Classic() : Cd()
{
    songs = nullptr;
}

Classic::Classic(const char * s, const char * s1, const char * s2, int n, double x) : Cd(s1, s2, n, x)
{
    songs = new char[std::strlen(s) + 1];
    std::strcpy(songs, s);
}

Classic::~Classic()
{
    delete [] songs;
}

void Classic::Report() const
{
    Cd::Report();
    if (songs == nullptr)
        std::cout << "No Songs!" << std::endl;
    else
        std::cout << "Songs: " << songs << std::endl;
}

Classic & Classic::operator=(const Classic & d)
{
    Cd::operator=(d);
    delete [] songs;
    songs = new char[std::strlen(d.songs) + 1];
    std::strcpy(songs, d.songs);
    return *this;
}

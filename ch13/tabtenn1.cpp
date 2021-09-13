/******************************************************************************
* File:             tabtenn1.cpp
*
* Author:           Joey Tsai  
* Created:          08/30/21 
* Description:      simple base-class methods
*****************************************************************************/


#include <iostream>
#include "tabtenn1.h"

void TableTennisPlayer::Name() const
{
    std::cout << lastname << ", " << firstname;
}

TableTennisPlayer::TableTennisPlayer(const string & fn, const string & ln, bool ht) : firstname(fn), lastname(ln), hasTable(ht){}

// RatedPlayer methods
RatedPlayer::RatedPlayer(unsigned int r, const string & fn, const string & ln, bool ht) : TableTennisPlayer(fn, ln, ht)
{
    rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp) : TableTennisPlayer(tp), rating(r){}


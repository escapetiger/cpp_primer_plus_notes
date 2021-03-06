/******************************************************************************
* File:             tabtenn0.cpp
*
* Author:           Joey Tsai  
* Created:          08/30/21 
* Description:      simple base-class methods
*****************************************************************************/

#include <iostream>
#include "tabtenn0.h"

void TableTennisPlayer::Name() const
{
    std::cout << lastname << ", " << firstname;
}

TableTennisPlayer::TableTennisPlayer(const string & fn, const string & ln, bool ht) : firstname(fn), lastname(ln), hasTable(ht){}


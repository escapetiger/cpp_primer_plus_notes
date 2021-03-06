/******************************************************************************
* File:             ex1.cpp
*
* Author:           Joey Tsai  
* Created:          08/30/21 
* Description:      application of Cow class
*****************************************************************************/

#include <iostream>
#include "cow.h"

int main(void)
{
    using std::cout;
    using std::endl;

    Cow c1("Maggie", "Dance", 93.5);
    Cow c2("Joey", "Game", 135.8);
    Cow c3 = c1;
    cout << "Cow #1\n" ;
    c1.ShowCow();
    cout << "Cow #2\n" ;
    c2.ShowCow();
    cout << "Cow #3\n" ;
    c3.ShowCow();

    return 0;
}

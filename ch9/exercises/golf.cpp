#include <iostream>
#include <cstring>
#include "golf.h"


void setgolf(golf & g, const char * name, int hc)
{
    std::strcpy(g.fullname, name);
    g.handicap = hc;
}

int setgolf(golf & g)
{
    return (std::strcmp(g.fullname, "")) ? 0 : 1;
}

void handicap(golf & g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf & g)
{
    std::cout << g.fullname << "\t"<< g.handicap << std::endl;
}

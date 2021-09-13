// ex6.cpp -- use Move class
// compiled with move.cpp

#include <iostream>
#include "move.h"

int main()
{
    using namespace std;
    Move m(1, 1);
    m.showmove();
    m = m.add(m);
    m = m.add(m);
    m.showmove();
    m.reset(2, 1);
    m.showmove();
    
    return 0;
}

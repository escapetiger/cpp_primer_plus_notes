// ex5.cpp -- user-defined conversion functions
// compiled with stonewt2.cpp
#include <iostream>
#include "stonewt2.h"

int main()
{
    using std::cout;
    using std::endl;
    Stonewt st1(9, 12);
    Stonewt st2(32.2);
    cout << "st1 = " << st1;
    cout << "st2 = " << st2;

    cout << "st1 + st2 = " << st1 + st2;
    cout << "st1 - st2 = " << st1 - st2;
    cout << "st1 * 1.5 = " << st1 * 1.5;
    cout << "1.5 * st1 = " << 1.5 * st1;

    st2.ipdmode();
    cout << "st2 = " << st2;

    st2.fpdmode();
    cout << "st2 = " << st2;
    
    st2.stnmode();
    cout << "st2 = " << st2;
    
    return 0;
}

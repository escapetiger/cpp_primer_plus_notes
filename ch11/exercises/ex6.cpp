// ex6.cpp -- realation operator for Stonewt class
// compiled with stonewt3.cpp
#include <iostream>
#include <cmath>
#include "stonewt3.h"

int main()
{
    using namespace std;
    Stonewt st_arr[6] =
    {
        Stonewt(11, 2),
        Stonewt(4, 3),
        Stonewt(5, 4)
    };
    for (int i = 0; i < 3; ++i)
        st_arr[i + 3] = Stonewt(50 * i + 12);

    Stonewt min(999999), max(0);
    int ct = 0;
    Stonewt st(11, 0);
    for (int i = 0; i < 6; ++i)
    {
        if (st_arr[i] < min)
            min = st_arr[i];
        if (st_arr[i] > max)
            max = st_arr[i];
        if (st_arr[i] > st)
            ++ct;
    }

    cout << "max(st_arr) = " << max;
    cout << "min(st_arr) = " << min;
    cout << "There are " << ct << " elements weighed more than 11 stones." << endl;

    return 0;
}

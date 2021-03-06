/******************************************************************************
* File:             iomanip.cpp
*
* Author:           Joey Tsai
* Created:          09/07/21
* Description:      using manipulators from iomanip
*****************************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>

int main(void)
{
    using namespace std;
    // use new standard manipulators
    cout << fixed << right;

    // use iomanip manipulators
    cout << setw(6) << "N"
         << setw(14) << "square root"
         << setw(15) << "fourth root"
         << endl;
    double root;
    for (int n = 0; n <= 100; n += 10)
    {
        root = sqrt(double(n));
        cout << setw(6) << setfill('.') << n << setfill(' ')
             << setw(14) << setprecision(3) << root
             << setw(15) << setprecision(4) << sqrt(root)
             << endl;
    }
    return 0;
}

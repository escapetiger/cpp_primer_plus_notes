/******************************************************************************
* File:             setf2.cpp
*
* Author:           Joey Tsai
* Created:          09/07/21
* Description:      using set() with 2 arguments to control formatting
*****************************************************************************/

#include <iostream>
#include <cmath>

int main(void)
{
    using namespace std;
    // use left justification, show the plus sign, show trailling zeros, with a precision of 3
    cout.setf(ios_base::left, ios_base::adjustfield);
    cout.setf(ios_base::showpos);
    cout.setf(ios_base::showpoint);
    cout.precision(3);

    // use e-notation and save old format setting
    ios_base::fmtflags old = cout.setf(ios_base::scientific, ios_base::floatfield);
    cout << "Left Justification:\n";
    long n;
    for (int n = 0; n < 41; n += 10)
    {
        cout.width(4);
        cout << n << "|";
        cout.width(12);
        cout << sqrt(double(n)) << "|\n";
    }

    // change to internal justification
    cout.setf(ios_base::internal, ios_base::adjustfield);
    // restore default floating-point display style
    cout.setf(old, ios_base::floatfield);

    cout << "Internal Justification:\n";
    for (int n = 0; n < 41; n += 10)
    {
        cout.width(4);
        cout << n << "|";
        cout.width(12);
        cout << sqrt(double(n)) << "|\n";
    }

    // use right justification, fixed notation
    cout.setf(ios_base::right, ios_base::adjustfield);
    cout.setf(ios_base::fixed, ios_base::floatfield);

    cout << "Right Justification:\n";
    for (int n = 0; n < 41; n += 10)
    {
        cout.width(4);
        cout << n << "|";
        cout.width(12);
        cout << sqrt(double(n)) << "|\n";
    }

    return 0;
}

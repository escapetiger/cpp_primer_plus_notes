/******************************************************************************
* File:             error4.cpp
*
* Author:           Joey Tsai
* Created:          09/05/21
* Description:
*****************************************************************************/

#include <iostream>
#include <cmath>
#include "exc_mean.h"
// function prototypes
double hmean(double a, double b);
double gmean(double a, double b);

int main(void)
{
    double x, y, z;
    std::cout << "Enter two numbers: ";
    while (std::cin >> x >> y)
    {
        try                                               // start of try block
        {
            z = hmean(x, y);
            std::cout << "Harmonic mean of " << x << " and " << y
                << " is " << z << std::endl;
            std::cout << "Geometric mean of " << x << " and " << y // bead design, it will print unnecessary strings first
                << " is " << gmean(x, y) << std::endl;
            std::cout << "Enter next set of numbers <q to quit>: ";
        }                                                 // end of try block
        catch (bad_hmean & bg)                            // start of exception handler
        {
            bg.mesg();
            std::cout << "Try again.\n";
            std::cout << "Enter a new pair of numbers: ";
            continue;
        }                                                 // end of exception handler
        catch (bad_gmean & hg)                            // start of exception handler
        {
            std::cout << hg.mesg();
            std::cout << "Values used: " << hg.v1 << ", "
                << hg.v2 << std::endl;
            std::cout << "Sorry, you don't get to play any more.\n";
            break;
        }                                                 // end of exception handler

    }
    std::cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean(a, b);
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean(a, b);
    return std::sqrt(a * b);
}

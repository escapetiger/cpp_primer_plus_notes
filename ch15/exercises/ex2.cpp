/******************************************************************************
* File:             ex2.cpp
*
* Author:           Joey Tsai
* Created:          09/05/21
* Description:      exception classes inherited from std::logic_error
*****************************************************************************/

#include <iostream>
#include <cmath>
#include <stdexcept>
#include "exc_mean.h"
// function prototypes
double hmean(double a, double b);
double gmean(double a, double b);

int main(void)
{
    double x, y, z1, z2;
    std::cout << "Enter two numbers: ";
    while (std::cin >> x >> y)
    {
        try                                               // start of try block
        {
            z1 = hmean(x, y);
            z2 = gmean(x, y);
            std::cout << "Harmonic mean of " << x << " and " << y
                << " is " << z1 << std::endl;
            std::cout << "Geometric mean of " << x << " and " << y 
                << " is " << z2 << std::endl;
            std::cout << "Enter next set of numbers <q to quit>: ";
        }                                                 // end of try block
        catch (std::logic_error & e)                            // start of exception handler
        {
            std::cout << e.what() << std::endl;
            std::cout << "Enter next set of numbers <q to quit>: ";
        }                                                 // end of exception handler

    }
    std::cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean("hmean(): invalid argument (a = -b).");
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean("gmean(): negative input.");
    return std::sqrt(a * b);
}

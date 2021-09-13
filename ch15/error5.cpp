/******************************************************************************
* File:             error5.cpp
*
* Author:           Joey Tsai
* Created:          09/05/21
* Description:      unwinding the stack
*****************************************************************************/

#include <iostream>
#include <cmath>
#include <string>
#include "exc_mean.h"

class demo
{
private:
    std::string word;
public:
    demo(const std::string & str)
    {
        word = str;
        std::cout << "demo " << word << " created\n";
    };
    virtual ~demo ()
    {
        std::cout << "demo " << word << " destroyed\n";
    };
    void show() const
    {
        std::cout << "demo " << word << " lives!\n";
    }

};
// function prototypes
double hmean(double a, double b);
double gmean(double a, double b);
double means(double a, double b);



int main(void)
{
    double x, y, z;
    {
        demo d1("found in block in main()");
        std::cout << "Enter two numbers: ";
        while (std::cin >> x >> y)
        {
            try                                               // start of try block
            {
                z = means(x, y);
                std::cout << "The mean mean of " << x << " and " << y
                          << " is " << z << std::endl;
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
        d1.show();
    }
    std::cout << "Bye!\n";
    std::cin.get();
    std::cin.get();
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

double means(double a, double b)
{
    double am, hm, gm;
    demo d2("found in means()");
    am = (a + b) / 2.0;                     // arithmetic mean
    try
    {
        hm = hmean(a, b);
        gm = gmean(a, b);
    }
    catch (bad_hmean & bg)                  // start of catch block
    {
        bg.mesg();
        std::cout << "Caught in means()\n";
        throw;                              // rethrows the exception
    }
    d2.show();
    return (am + hm + gm) / 3.0;
}

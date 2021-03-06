/******************************************************************************
* File:             exc_mean.h
*
* Author:           Joey Tsai
* Created:          09/05/21
* Description:      exception classes for hmean() and gmean()
*****************************************************************************/

#ifndef EXC_MEAN_H
#define EXC_MEAN_H

#include <iostream>
class bad_hmean
{
private:
    double v1;
    double v2;
public:
    bad_hmean(double a = 0, double b = 0) : v1(a), v2(b) {};
    void mesg()
    {
        std::cout << "hmean(" << v1 << ", " << v2 << ") "
                  << "invalid arguments: a = -b\n";
    };
};
class bad_gmean
{
public:
    double v1;
    double v2;
    bad_gmean(double a = 0, double b = 0) : v1(a), v2(b) {};
    const char * mesg()
    {
        return "gmean() arguments should be >= 0\n";
    };
};


#endif /* ifndef EXC_MEAN_H*/

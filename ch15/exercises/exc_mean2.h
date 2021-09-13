/******************************************************************************
* File:             exc_mean2.h
*
* Author:           Joey Tsai
* Created:          09/05/21
* Description:      exception classes for hmean() and gmean()
*****************************************************************************/

#ifndef EXC_MEAN_H
#define EXC_MEAN_H

#include <iostream>
#include <string>
#include <stdexcept>
class bad_hmean : public std::logic_error
{
private:
    double v1;
    double v2;
public:
    bad_hmean(const std::string & s = "bad_hmean error:\n", double a = 0.0, double b = 0.0) : std::logic_error(s), v1(a), v2(b) {};
    void mesg()
    {
        std::cout << "hmean(" << v1 << ", " << v2 << "): invalid argument (a = -b)" << std::endl;
    };
};

class bad_gmean : public std::logic_error
{
private:
    double v1;
    double v2;
public:
    bad_gmean(const std::string & s = "bad_gmean error:\n", double a = 0.0, double b = 0.0) : std::logic_error(s), v1(a), v2(b) {};
    void mesg()
    {
        std::cout << "gmean() arguments should be >=0: a = " << v1
                  << ", b = " << v2 << std::endl;
    };

};


#endif /* ifndef EXC_MEAN_H*/

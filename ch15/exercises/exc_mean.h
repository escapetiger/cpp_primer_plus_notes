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
#include <string>
#include <stdexcept>
class bad_hmean : public std::logic_error
{
public:
    bad_hmean(const std::string & s) : std::logic_error(s){};
};

class bad_gmean : public std::logic_error
{
public:
    bad_gmean(const std::string & s) : std::logic_error(s){};
};


#endif /* ifndef EXC_MEAN_H*/

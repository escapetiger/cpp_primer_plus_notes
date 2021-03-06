/******************************************************************************
* File:             studentc.cpp
*
* Author:           Joey Tsai
* Created:          09/03/21
* Description:      Student class using containment
*****************************************************************************/

#include "studentc.h"
using std::ostream;
using std::istream;
using std::endl;
using std::string;

// private method
std::ostream & Student::arr_out(std::ostream & os) const
{
    int i;
    int lim = scores.size();
    if (lim > 0)
    {
        for (i = 0; i < lim; ++i)
        {
            os << scores[i] << " ";
            if (i % 5 == 4) os << endl;
        }
        if (i % 5 != 0) os << endl;
    }
    else
        os << " empty array ";
    return os;
}

// public methods
double Student::Average() const
{
    return (scores.size() > 0) ? scores.sum() / scores.size() : 0;
}

const std::string & Student::Name() const
{
    return name;
}

double & Student::operator[](int i)
{
    return scores[i];
}

double Student::operator[](int i) const
{
    return scores[i];
}

// friends
// use string version of operator>>()
std::istream & operator>>(std::istream & is, Student & stu)
{
    is >> stu.name;
    return is;
}

// use string friend getline(istream & is, const string &)
std::istream & getline(std::istream & is, Student & stu)
{
    getline(is, stu.name);
    return is;
}

// use string version of operator<<()
std::ostream & operator<<(std::ostream & os, const Student & stu)
{
    os << "Scores for " << stu.name << ":\n";
    stu.arr_out(os);
    return os;
}

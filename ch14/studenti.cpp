/******************************************************************************
* File:             studenti.cpp
*
* Author:           Joey Tsai
* Created:          09/03/21
* Description:      Student class using private inheritance
*****************************************************************************/

#include "studenti.h"
using std::ostream;
using std::istream;
using std::endl;
using std::string;

// private method
std::ostream & Student::arr_out(std::ostream & os) const
{
    int i;
    int lim = ArrayDb::size();
    if (lim > 0)
    {
        for (i = 0; i < lim; ++i)
        {
            os << ArrayDb::operator[](i) << " ";
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
    return (ArrayDb::size() > 0) ? ArrayDb::sum() / ArrayDb::size() : 0;
}

const std::string & Student::Name() const
{
    return (const std::string &) * this;
}

double & Student::operator[](int i)
{
    return ArrayDb::operator[](i);
}

double Student::operator[](int i) const
{
    return ArrayDb::operator[](i);
}

// friends
// use string version of operator>>()
std::istream & operator>>(std::istream & is, Student & stu)
{
    is >> (string &)stu;
    return is;
}

// use string friend getline(istream & is, const string &)
std::istream & getline(std::istream & is, Student & stu)
{
    getline(is, (string &)stu);
    return is;
}

// use string version of operator<<()
std::ostream & operator<<(std::ostream & os, const Student & stu)
{
    os << "Scores for " << (string &)stu << ":\n";
    stu.arr_out(os);
    return os;
}

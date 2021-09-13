// mytime4.h -- Time class before operator overloading
#ifndef MYTIME4_H
#define MYTIME4_H

#include <ostream>
class Time
{
private:
    int hours;
    int minutes;

public:
    Time();
    Time(int h, int m = 0);
    virtual ~Time();
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    // Time operator+(const Time & t) const;
    // Time operator-(const Time & t) const;    
    // Time operator*(double n) const;

    // friend functions
    friend Time operator+(const Time & t1, const Time & t2);
    friend Time operator-(const Time & t1, const Time & t2);
    friend Time operator*(const Time & t, double n);
    friend Time operator*(double m, const Time & t)
    {
        return t * m; // inline definition
    }
    friend std::ostream & operator<<(std::ostream & os, const Time & t);
    void Show() const;
};

#endif /* MYTIME4_H */


// mytime2.cpp -- implementing Time methods
#include <iostream>
#include "mytime2.h"

void Time::AddHr(int h)
{
    hours += h;
}

void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}

void Time::Show() const
{
    std::cout << hours << " hours, " << minutes << " minutes";
}

Time Time::operator+(const Time & t) const
{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
	return sum;
}
Time Time::operator*(double n) const
{
    Time res;
    long totalminutes = hours * n * 60 + minutes * n;
    res.hours = totalminutes / 60;
    res.minutes = totalminutes % 60;

	return res;
}

Time Time::operator-(const Time & t) const
{
    Time diff;
    int tot1, tot2;
    tot1 = t.minutes + 60 * t.hours;
    tot2 = minutes + 60 * hours;
    diff.minutes = (tot2 - tot1) % 60;
    diff.hours = (tot2 - tot1) / 60;

	return diff;
}

Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}

Time::~Time()
{
}


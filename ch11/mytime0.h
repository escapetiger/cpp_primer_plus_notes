// mytime0.h -- Time class before operator overloading
#ifndef MYTIME0_H
#define MYTIME0_H

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
    Time Sum(const Time & t) const;
    void Show() const;
};

#endif /* MYTIME0_H */


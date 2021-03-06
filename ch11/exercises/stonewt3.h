// stonewt3.h -- definition for the Stonewt class
#ifndef STONEWT3_H
#define STONEWT3_H

#include <iostream>
class Stonewt
{
public:
    enum Mode {STN, IPD, FPD};
private:
    enum {Lbs_per_stn = 14};      // pounds per stone
    int stone;                    // whole stones
    double pds_left;              // fractional pounds
    double pounds;                // entire weight in pounds
    Mode mode;

public:
    Stonewt();                    // default constructor
    Stonewt(double lbs);          // consturctor for double pounds
    Stonewt(int stn, double lbs); // constructor for stone, lbs
    virtual ~Stonewt();
    void stnmode(){ mode = STN; };
    void ipdmode(){ mode = IPD; };
    void fpdmode(){ mode = FPD; };
    // override operators
    friend std::ostream & operator<<(std::ostream & os, const Stonewt & obj);
    Stonewt operator+(Stonewt & st);
    Stonewt operator-(Stonewt & st);
    Stonewt operator*(double n);
    friend Stonewt operator*(double n, Stonewt & st){ return st * n; };
    bool operator>(Stonewt & st);
    bool operator<(Stonewt & st);
    bool operator>=(Stonewt & st);
    bool operator<=(Stonewt & st);
    bool operator==(Stonewt & st);
    bool operator!=(Stonewt & st);
    // conversion functions
    operator int() const;
    operator double() const;
};

#endif /* STONEWT3_H */

// stonewt1.h -- definition for the Stonewt class
#ifndef STONEWT1_H
#define STONEWT1_H

class Stonewt
{
private:
    enum {Lbs_per_stn = 14};      // pounds per stone
    int stone;                    // whole stones
    double pds_left;              // fractional pounds
    double pounds;                // entire weight in pounds

public:
    Stonewt();                    // default constructor
    Stonewt(double lbs);          // consturctor for double pounds
    Stonewt(int stn, double lbs); // constructor for stone, lbs
    virtual ~Stonewt();
    void show_lbs() const;        // show weight inpounds format
    void show_stn() const;        // show weight in stone format
    // conversion functions
    operator int() const;
    operator double() const;
};

#endif /* STONEWT1_H */

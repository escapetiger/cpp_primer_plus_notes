// stonewt3.cpp -- Stonewt methods
#include <iostream>
#include "stonewt3.h"

// default construtor, wt = 0
Stonewt::Stonewt()
{
    stone = pounds = pds_left = 0;
    mode = FPD;
}

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs)
{
    stone = int (lbs) / Lbs_per_stn; // integer division
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
    mode = FPD;
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
    mode = FPD;
}

std::ostream & operator<<(std::ostream & os, const Stonewt & obj)
{
    switch (obj.mode)
    {
        case Stonewt::STN:
        os << obj.stone << " stone, " << obj.pds_left << " pounds\n";
        break;
        case Stonewt::IPD:
        os << int (obj.pounds) << " pounds\n";
        break;
        case Stonewt::FPD:
        os << obj.pounds << " pounds\n";
    }

    return os;
}
Stonewt Stonewt::operator*(double n)
{
	return Stonewt(pounds * n);
}

Stonewt Stonewt::operator+(Stonewt & st)
{
	return Stonewt(pounds + st.pounds);
}

Stonewt Stonewt::operator-(Stonewt & st)
{
	return Stonewt(pounds - st.pounds);
}
bool Stonewt::operator!=(Stonewt & st)
{
	return *this == st;
}

bool Stonewt::operator<(Stonewt & st)
{
	return this->pounds < st.pounds;
}

bool Stonewt::operator<=(Stonewt & st)
{
	return this->pounds <= st.pounds;
}

bool Stonewt::operator==(Stonewt & st)
{
	return this->pounds == st.pounds;
}

bool Stonewt::operator>(Stonewt & st)
{
	return !(*this <= st);
}

bool Stonewt::operator>=(Stonewt & st)
{
	return !(*this < st);
}

Stonewt::~Stonewt()
{
}

// conversion functions
Stonewt::operator int() const
{
    return (pounds + 0.5);
}

Stonewt::operator double() const
{
    return pounds;
}

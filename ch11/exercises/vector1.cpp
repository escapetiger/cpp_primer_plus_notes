// vector.cpp -- methods for the Vector class
#include <cmath>
#include "vector1.h"
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
    // compute degrees in one radian
    const double Rad_to_deg = 45.0 / atan(1.0);
    // should be about 57.2957795130823

    Vector::Vector()
    {
        x = y = 0.0;
        mode = RECT;
    }

    Vector::Vector(double n1, double n2, Mode form)
    {
        mode = form;
        switch (mode)
        {
        case RECT:
            x = n1;
            y = n2;
            break;
        case POL:
            set_x(n1, n2);
            set_y(n1, n2);
            break;
        default:
            cout << "Incorrect 3rd argument to Vector() --";
            cout << "vector set to 0\n";
            x = y = 0.0;
            mode = RECT;
        }
    }



    Vector Vector::operator*(double n) const
    {
        return Vector(n * x, n * y, RECT);
    }

    Vector operator*(double n, const Vector & a)
    {
        return a * n;
    }

    Vector Vector::operator+(const Vector & b) const
    {
        return Vector(x + b.x, y + b.y, RECT);
    }

    Vector Vector::operator-() const
    {
        return Vector(-x, -y, RECT);
    }

    std::ostream & operator<<(std::ostream & os, const Vector & v)
    {
        if (v.mode == Vector::RECT)
            os << "(x, y) = (" << v.x << ", " << v.y << ")";
        else if (v.mode == Vector::POL)
        {
            os << "(m, a) = (" << v.magval() << ", " << v.angval() * Rad_to_deg << ")";
        }
        else
        {
            os << "Vector object mode is invalid";
        }
        return os;
    }

    void VECTOR::Vector::polar_mode()
    {
        mode = POL;
    }

    void VECTOR::Vector::rect_mode()
    {
        mode = RECT;
    }

    void VECTOR::Vector::reset(double n1, double n2, Mode form)
    {
        mode = form;
        switch (mode)
        {
        case RECT:
            x = n1;
            y = n2;
            break;
        case POL:
            set_x(n1, n2);
            set_y(n1, n2);
            break;
        default:
            cout << "Incorrect 3rd argument to Vector() --";
            cout << "vector set to 0\n";
            x = y = 0.0;
            mode = RECT;
        }
    }

    double VECTOR::Vector::set_ang() const
    {
        return (x == 0.0 && y == 0.0) ? 0.0 : atan2(y, x) / Rad_to_deg;
    }

    double VECTOR::Vector::set_mag() const
    {
        return sqrt(x * x + y * y);
    }

    void VECTOR::Vector::set_x(double mag, double ang)
    {
        x = mag * cos(ang);
    }

    void VECTOR::Vector::set_y(double mag, double ang)
    {
        y = mag * sin(ang);
    }

    VECTOR::Vector::~Vector()
    {
    }


}

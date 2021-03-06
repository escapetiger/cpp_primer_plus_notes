// vector1.h -- Vector calss with <<, mode state
#ifndef VECTOR1_H
#define VECTOR1_H

#include <iostream>
namespace VECTOR
{
    class Vector
    {
    public:
        enum Mode {RECT, POL};
    private:
        double x;   // horizontal value
        double y;   // vertical value
        Mode mode;  // RECT or POL
        // private method for setting values
        double set_mag() const;
        double set_ang() const;
        void set_x(double mag, double ang);
        void set_y(double mag, double ang);

    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        void reset(double n1, double n2, Mode form = RECT);
        virtual ~Vector();
        double xval() const {return x;};                // report x value
        double yval() const {return y;};                // report y value
        double magval() const {return set_mag();};            // report magnitude
        double angval() const {return set_ang();};            // report angle
        void polar_mode();                              // set mode to POL
        void rect_mode();                               // set mode to RECT
        // operator overloading
        Vector operator+(const Vector & b) const;
        Vector operator-(const Vector & b) const;
        Vector operator-() const;
        Vector operator*(double n) const;
        // friends
        friend Vector operator*(double n, const Vector & a);
        friend std::ostream & operator<<(std::ostream & os, const Vector & v);
        
    };


}
#endif /* VECTOR1_H */

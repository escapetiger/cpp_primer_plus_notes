// complex0.h -- Complex class
#ifndef COMPLEX0_H
#define COMPLEX0_H

#include <iostream>
class Complex
{
private:
    double real;
    double imaginary;

public:
    Complex();
    Complex(double re, double im);
    virtual ~Complex();

    // stream operators
    friend std::ostream & operator<<(std::ostream & os, const Complex & obj);
    friend std::istream & operator>>(std::istream & is, Complex & obj);
    // algebra operators
    Complex operator~() const;
    Complex operator+(const Complex & obj) const;
    Complex operator-(const Complex & obj) const;
    Complex operator*(const Complex & obj) const;
    Complex operator*(double k) const;
    friend Complex operator*(double k, const Complex & obj) { return obj * k; };

};

#endif /* COMPLEX0_H */

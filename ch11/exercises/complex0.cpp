// complex0.cpp -- definitions of member functions in Complex class
#include <iostream>
#include "complex0.h"
Complex::Complex()
{
    real = imaginary = 0;
}

Complex::Complex(double re, double im)
{
    real = re;
    imaginary = im;
}

Complex Complex::operator*(const Complex & obj) const
{
    Complex res;
    res.real = real * obj.real - imaginary * obj.imaginary;
    res.imaginary = real * obj.imaginary + imaginary * obj.real;
	return res;
}

Complex Complex::operator*(double k) const
{
    return Complex(k * real, k* imaginary);
}

Complex Complex::operator+(const Complex & obj) const
{
    return Complex(real + obj.real, imaginary + obj.imaginary);
}

Complex Complex::operator-(const Complex & obj) const
{
    return Complex(real - obj.real, imaginary - obj.imaginary);
}

Complex Complex::operator~() const
{
    return Complex(real, -imaginary);
}

std::ostream & operator<<(std::ostream & os, const Complex & obj)
{
    os << "(" << obj.real << ", " << obj.imaginary << "i)";
	return os;
}

std::istream & operator>>(std::istream & is, Complex & obj)
{
    using std::cout;
    cout << "real: ";
    is >> obj.real;
    cout << "imaginary: ";
    is >> obj.imaginary;
	return is;
}

Complex::~Complex()
{
}


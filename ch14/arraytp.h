/******************************************************************************
* File:             arraytp.h
*
* Author:           Joey Tsai
* Created:          09/04/21
* Description:      Array Template
*****************************************************************************/

#ifndef ARRAYTP_H
#define ARRAYTP_H

#include <iostream>
#include <cstdlib>

template <typename T, int n>
class ArrayTP
{
private:
    T ar[n];

public:
    ArrayTP() {};
    explicit ArrayTP(const T & v);
    virtual T & operator[](int i);
    virtual T operator[](int i) const; // operator[] for const ArrayTP<T, n>
};

template <typename T, int n>
ArrayTP<T, n>::ArrayTP(const T & v)
{
    for (int i = 0; i < n; ++i)
        ar[i] = v;
}

template <typename T, int n>
T & ArrayTP<T, n>::operator[](int i)
{
    if (i < 0 || i >= n)
    {
        std::cerr << "Error in array limits: " << i
                  << " is out of range\n";
        std::exit(EXIT_FAILURE);
    }
    return ar[i];
}

template <typename T, int n>
T ArrayTP<T, n>::operator[](int i) const
{
    if (i < 0 || i >= n)
    {
        std::cerr << "Error in array limits: " << i
                  << " is out of range\n";
        std::exit(EXIT_FAILURE);
    }
    return ar[i];
}

#endif /* ARRAYTP_H */
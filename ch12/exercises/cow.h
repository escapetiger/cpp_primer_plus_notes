/******************************************************************************
* File:             cow.h
*
* Author:           Joey Tsai
* Created:          08/29/21
* Description:      a class for cow
*****************************************************************************/

#ifndef COW_H
#define COW_H

class Cow
{
private:
    char name[20];
    char * hobby;
    double weight;

public:
    Cow();
    Cow(const char * nm, const char * ho, double wt);
    Cow(const Cow & c);
    virtual ~Cow();
    Cow & operator=(const Cow & c);
    void ShowCow() const; // display all cow data
};

#endif /* COW_H */

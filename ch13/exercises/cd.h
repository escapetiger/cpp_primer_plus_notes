/******************************************************************************
* File:             cd.h
*
* Author:           Joey Tsai  
* Created:          09/02/21 
* Description:      Cd class declaration
*****************************************************************************/

#ifndef CD_H
#define CD_H

class Cd
{
private:
    char * performers;
    char * label;
    int selections; // number of selections
    double playtime; // playing time in minutes
    
public:
    Cd();
    Cd(const char * s1, const char * s2, int n, double x);
    Cd(const Cd & d);
    virtual ~Cd();
    virtual void Report() const;
    virtual Cd & operator=(const Cd & d);
};

#endif /* CD_H */

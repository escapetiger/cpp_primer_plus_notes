/******************************************************************************
* File:             classic.h
*
* Author:           Joey Tsai  
* Created:          09/02/21 
* Description:      Classic class declarations 
*****************************************************************************/

#ifndef CLASSIC_H
#define CLASSIC_H

#include "cd.h"
class Classic : public Cd
{
private:
    char * songs;

public:
    Classic();
    Classic(const char * s, const char * s1, const char * s2, int n, double x);
    virtual ~Classic();
    virtual void Report() const;
    virtual Classic & operator=(const Classic & d);
};

#endif /* CLASSIC_H */

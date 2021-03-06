/******************************************************************************
* File:             vport.h
*
* Author:           Joey Tsai  
* Created:          09/02/21 
* Description:      VintagePort class decalaration
*****************************************************************************/

#ifndef VPORT_H
#define VPORT_H

#include "port.h"
class VintagePort : public Port
{
private:
    char * nickname;
    int year;

public:
    VintagePort();
    VintagePort(const char * br, int b, const char * nn, int y);
    VintagePort(const VintagePort & vp);
    virtual ~VintagePort() { delete [] nickname; };
    VintagePort & operator=(const VintagePort & vp);
    void Show() const;
    friend std::ostream & operator<<(std::ostream & os, const VintagePort & p);
};

#endif /* VPORT_H */

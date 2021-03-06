/******************************************************************************
* File:             vport.cpp
*
* Author:           Joey Tsai
* Created:          09/02/21
* Description:      VintagePort class methods
*****************************************************************************/

#include "vport.h"
#include <cstring>

VintagePort::VintagePort() : Port()
{
    nickname = nullptr;
    year = 0;
}

VintagePort::VintagePort(const char * br, int b, const char * nn, int y) : Port(br, "vintage", b)
{
    nickname = new char[std::strlen(nn) + 1];
    std::strcpy(nickname, nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort & vp) : Port(vp)
{
    nickname = new char[std::strlen(vp.nickname) + 1];
    std::strcpy(nickname, vp.nickname);
    year = vp.year;
}

VintagePort & VintagePort::operator=(const VintagePort & vp)
{
    if (this == &vp)
        return *this;
    Port::operator=(vp);
    delete [] nickname;
    nickname = new char[std::strlen(vp.nickname) + 1];
    std::strcpy(nickname, vp.nickname);
    year = vp.year;

    return *this;
}

void VintagePort::Show() const
{
    Port::Show();
    if (nickname == nullptr)
        std::cout << "No nickname!" << std::endl;
    else
        std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Year: " << year << std::endl;
}

std::ostream & operator<<(std::ostream & os, const VintagePort & p)
{
    os << (const Port &) p;
    os << ", " << p.nickname << ", " << p.year;
    return os;
}

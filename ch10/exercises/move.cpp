// move.cpp -- member functions definitions of Move class
#include <iostream>
#include "move.h"
Move::Move(double a, double b)
{
    x = a;
    y = b;
}

Move Move::add(const Move & m) const
{
	return Move(this->x + m.x, this->y + m.y);
}

void Move::reset(double a, double b)
{
    x = a;
    y = b;
}

void Move::showmove() const
{
    std::cout << "("<< x << ", " << y << ")" << std::endl;
}

Move::~Move()
{
}


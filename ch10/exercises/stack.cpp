// stack.cpp -- Stack member functions
#include "stack.h"
Stack::Stack()
{
    top = 0;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == MAX;
}

bool Stack::pop(Item & item)
{
    if (top == 0)
        return false;
    item = items[--top];
    return true;
}

bool Stack::push(const Item & item)
{
    if (top >= MAX)
        return false;
    items[top++] = item;
    return true;
}

Stack::~Stack()
{
}

/******************************************************************************
* File:             stack.cpp
*
* Author:           Joey Tsai
* Created:          08/30/21
* Description:      member functions of Stack class
*****************************************************************************/

#include <iostream>
#include "stack.h"

Stack::Stack(const Stack & st)
{
    pitems = new Item[st.size];
    for (int i = 0; i < st.size; ++i)
        pitems[i] = st.pitems[i];
    size = st.size;
    top = st.top;
}

Stack::Stack(int n)
{
    pitems = new Item[n];
    size = 0;
    top = 0;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == MAX - 1;
}

Stack & Stack::operator=(const Stack & st)
{
    delete [] pitems;
    pitems = new Item[st.size];
    for (int i = 0; i < st.size; ++i)
        pitems[i] = st.pitems[i];
    size = st.size;
    top = st.top;

    return *this;
}

bool Stack::pop(Item & item)
{
    if (isempty())
        return false;
    item = pitems[--top];
    --size;
    return true;
}

bool Stack::push(const Item & item)
{
    if (isfull())
        return false;
    pitems[top++] = item;
    ++size;
    return true;
}

Stack::~Stack()
{
    delete [] pitems;
}

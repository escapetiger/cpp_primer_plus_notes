/******************************************************************************
* File:             stack.h
*
* Author:           Joey Tsai  
* Created:          08/30/21 
* Description:      class declaration for the stack ADT
*****************************************************************************/

#ifndef STACK_H
#define STACK_H

typedef unsigned long Item;
class Stack
{
private:
    enum {MAX = 10}; // constant specific to class
    Item * pitems;   // holds stack items
    int size;        // number of elements in stack
    int top;         // index for top stack item

public:
    Stack(int n = MAX); // create stack with n elements
    Stack(const Stack & st);
    virtual ~Stack();
    bool isempty() const;
    bool isfull() const;
    // push() returns false if stack already is full, true otherwise
    bool push(const Item & item); // add item to stack
    // pop() returns false if stack already is empty, true otehrwise
    bool pop(Item & item); // pop top itno item
    Stack & operator=(const Stack & st);
};

#endif /* STACK_H */

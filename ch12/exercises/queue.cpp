/******************************************************************************
* File:             queue.cpp
*
* Author:           Joey Tsai
* Created:          08/29/21
* Description:      Queue and Customer methods
*****************************************************************************/

#include "queue.h"
#include <cstdlib>

// Queue methods
Queue::Queue(int qs) : qsize(qs)
{
    front = rear = nullptr;
    items = 0;
}

// Place front item into item variable and remove from queue
bool Queue::dequeue(Item & item)
{
    if (front == nullptr)
        return false;
    item = front->item;  // set item to first item in queue
    items--;
    Node * temp = front; // save location of first item
    front = front->next; // reset front to next item
    delete temp;         // delete former first item
    if (items == 0)
        rear = nullptr;
    return true;
}

// Add item to queue
bool Queue::enqueue(const Item & item)
{
    if (isfull())
        return false;
    Node * add = new Node;
    add->item = item;
    add->next = nullptr;
    items++;
    if (front == nullptr) // if queue is empty
        front = add;      // place item at front
    else
        rear->next = add; // else place at rear
    rear = add;           // have rear point to new node
    return true;
}

bool Queue::isempty() const
{
    return items == 0;
}

bool Queue::isfull() const
{
    return items == qsize;
}

int Queue::queuecount() const
{
    return items;
}

// time set to a random value in the range 1 - 3
void Customer::set(long when)
{
    processtime = std::rand() % 3 + 1;
    arrive = when;
}

Customer::~Customer()
{
}

Queue::~Queue()
{
    Node * temp;
    while (front != nullptr)   // while queue is not yet empty
    {
        temp = front;          // save address of front item
        front = front->next;   // reset pointer to next item
        delete temp;           // delete former front
    }
}

/******************************************************************************
* File:             queuetp.h
*
* Author:           Joey Tsai
* Created:          nullptr9/nullptr5/21
* Description:      queue template with a nested class
*****************************************************************************/

#ifndef QUEUETP_H
#define QUEUETP_H

template <typename Item>
class QueueTP
{
private:
    enum {Q_SIZE = 10};
    // Node is a nested class definition
    class Node
    {
    public:
        Item item;
        Node * next;
        Node(const Item & i) : item(i), next(nullptr) {}
    };
    Node * front;    // pointer to front of Queue
    Node * rear;     // pointer to rear of Queue
    int items;       // current number of items in Queue
    const int qsize; // maximum number of items in Queue
    QueueTP(const QueueTP & q) : qsize(0) {}
    QueueTP & operator=(const QueueTP & q)
    {
        return *this;
    }
public:
    QueueTP(int qs = Q_SIZE);
    virtual ~QueueTP();
    bool isempty() const
    {
        return items == 0;
    }
    bool isfull() const
    {
        return items == qsize;
    }
    int queuecount() const
    {
        return items;
    }
    bool enqueue(const Item & item); // add item to end
    bool dequeue(Item & item);       // remove item from front
};

// QueueTP methods
template <typename Item>
QueueTP<Item>::QueueTP(int qs) : qsize(qs)
{
    front = rear = nullptr;
    items = 0;
}

template <typename Item>
QueueTP<Item>::~QueueTP()
{
    Node * temp;
    while (front != nullptr) // while queue is not yet empty
    {
        temp = front;        // save address of front item
        front = front->next; // reset pointer to next item
        delete temp;         // delete former front
    }
}

// Add item to queue
template <typename Item>
bool QueueTP<Item>::enqueue(const Item & item)
{
    if (isfull())
        return false;
    Node * add = new Node(item); // create new node
    items++;
    if (front == nullptr)        // if queue is empty
        front = add;             // place item at front
    else
        rear->next = add;        // else place at rear
    rear = add;                  // have rear point to new node
    return true;
}

// Place front item into item variable and remove from queue
template <typename Item>
bool QueueTP<Item>::dequeue(Item & item)
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

#endif /* QUEUETP_H */

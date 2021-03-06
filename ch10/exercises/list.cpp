// list.cpp -- member functions of List class
#include <iostream>
#include "list.h"
List::List()
{
    arr_ = new Item[ARSIZE_MAX];
    begin_ = arr_;
    end_ = arr_;
}

List::List(const Item arr[], int n)
{
    if (n > ARSIZE_MAX)
    {
        std::cerr << "The size of array should be no more than " << ARSIZE_MAX << std::endl;
        abort();
    }
    else
    {
        arr_ = new Item[n];
        for (int i = 0; i < n; ++i)
            arr_[i] = arr[i];
        begin_ = arr_;
        end_ = arr_ + n;
    }
}

bool List::isempty(const List & lst)
{
    return begin_ == end_;
}

bool List::isfull(const List & lst)
{
    return begin_ + ARSIZE_MAX == end_ ;
}
void List::append(const Item & item)
{
    if (isfull(*this))
        std::cout << "The list is full." << std::endl;
    else
        *(end_++) = item;
}

void List::visit(void (*pf)(Item &))
{
    for (Item * pt = begin_; pt != end_; ++pt)
        pf(*pt);
    std::cout << std::endl;
}



List::~List()
{
}

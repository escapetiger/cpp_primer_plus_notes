// list.h -- a simple List class
#ifndef LIST_H
#define LIST_H

typedef int Item;
class List
{
private:
    static const int ARSIZE_MAX = 5;
    Item *arr_;
    Item *begin_;
    Item *end_;

public:
    List();
    List(const Item arr[], int n);
    virtual ~List();
    bool isempty(const List & lst);
    bool isfull(const List & lst);
    void append(const Item & item);
    void visit(void (*pf)(Item &));
};

#endif /* LIST_H */

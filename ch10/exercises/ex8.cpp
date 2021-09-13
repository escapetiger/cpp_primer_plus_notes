// ex8.cpp -- use List class
#include <iostream>
#include "list.h"

void addone(Item & item);
void show(Item & item);
int main()
{
    using namespace std;
    typedef int Item;
    Item arr[] = {1, 2, 3};
    List lst1(arr, 3);
    lst1.visit(addone);
    lst1.visit(show);
    lst1.append(1);
    lst1.append(2);
    lst1.visit(show);
    lst1.append(1);
    lst1.visit(show);
    lst1.append(1);
    lst1.visit(show);
    
    return 0;
}
void addone(Item & item)
{
    item = item + 1;
}

void show(Item & item)
{
    std::cout << item << " ";
}

/******************************************************************************
* File:             list.cpp
*
* Author:           Joey Tsai  
* Created:          09/06/21 
* Description:      using a list
*****************************************************************************/

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

void outint(int n) { std::cout << n << " "; }

int main(void)
{
    using namespace std;
    list<int> one(5, 2);
    int stuff[5] = {1, 2, 4, 8, 16};
    list<int> two;
    two.insert(two.begin(), stuff, stuff + 5);
    int more[6] = {6, 4, 2, 4, 6, 5};
    list<int> three(two);
    three.insert(three.end(), more, more + 6);
    
    cout << "List one: ";
    for_each(one.begin(), one.end(), outint);
    cout << endl;

    cout << "List two: ";
    for_each(two.begin(), two.end(), outint);
    cout << endl;

    cout << "List three: ";
    for_each(three.begin(), three.end(), outint);
    cout << endl;

    cout << "List three minus 2s: ";
    three.remove(2);
    for_each(three.begin(), three.end(), outint);
    cout << endl;

    cout << "List three after splice: ";
    three.splice(three.begin(), one);
    for_each(three.begin(), three.end(), outint);
    cout << endl;
    cout << "List one: ";
    for_each(one.begin(), one.end(), outint);
    cout << endl;

    cout << "List three after unique: ";
    three.unique();
    for_each(three.begin(), three.end(), outint);
    cout << endl;

    cout << "List three after sort & unique: ";
    three.sort();
    for_each(three.begin(), three.end(), outint);
    cout << endl;

    cout << "Sorted two merged into three: ";
    two.sort();
    three.merge(two);
    for_each(three.begin(), three.end(), outint);
    cout << endl;

    return 0;
}

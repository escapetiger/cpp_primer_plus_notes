/******************************************************************************
* File:             ex4.cpp
*
* Author:           Joey Tsai
* Created:          09/07/21
* Description:
*****************************************************************************/

#include <iostream>
#include <algorithm>
#include <iterator>

const int ARR_SIZE = 5;
void show(long l);
int reduce(long ar[], int n);

int main(void)
{
    using std::cin;
    using std::cout;
    using std::endl;
    int i = 0;
    long ar[ARR_SIZE];
    cout << "Enter an long array <q to quit>: ";
    while (i < ARR_SIZE && cin >> ar[i])
        i++;
    while (i < ARR_SIZE)
        ar[i++] = 0;

    int n = i;
    cout << "ar: ";
    std::for_each(ar, ar + n, show);
    cout << endl;

    n = reduce(ar, ARR_SIZE);
    cout << "After reduce(), ar: ";
    std::for_each(ar, ar + n, show);
    cout << endl;

    return 0;
}

int reduce(long ar[], int n)
{
    std::sort(ar, ar + n);
    int len;
    auto rear = std::unique(ar, ar + n);
    len = rear - ar;
    return len;
}

void show(long l)
{
    std::cout << l << ' ';
}

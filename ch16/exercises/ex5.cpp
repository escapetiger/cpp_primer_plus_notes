/******************************************************************************
* File:             ex5.cpp
*
* Author:           Joey Tsai
* Created:          09/07/21
* Description:      reduce template
*****************************************************************************/


#include <iostream>
#include <algorithm>
#include <iterator>

const int ARR_SIZE = 5;
template <typename T>
int reduce(T ar[], int n);

template <typename T>
void show(T l);

template <typename T>
void test(T ar[]);

int main(void)
{
    std::cout << "string data test:\n";
    std::string * sarr;
    test(sarr);

    long * larr;
    std::cout << "long data test:\n";
    test(larr);
    return 0;
}

template <typename T>
int reduce(T ar[], int n)
{
    std::sort(ar, ar + n);
    int len;
    auto rear = std::unique(ar, ar + n);
    len = rear - ar;
    return len;
}

template <typename T>
void show(T l)
{
    std::cout << l << ' ';
}

template <typename T>
void test(T ar[])
{
    using std::cin;
    using std::cout;
    using std::endl;
    int i = 0;
    ar = new T[ARR_SIZE];
    cout << "Enter an array <q to quit>: ";
    while (i < ARR_SIZE && cin >> ar[i])
        i++;
    if (i < ARR_SIZE)
    {
        cout << "Input Error!" << endl;
        exit(EXIT_FAILURE);
    }
    while (cin.get() != '\n')
        continue;

    int n = i;
    cout << "ar: ";
    std::for_each(ar, ar + n, show<T>);
    cout << endl;

    n = reduce(ar, ARR_SIZE);
    cout << "After reduce(), ar: ";
    std::for_each(ar, ar + n, show<T>);
    cout << endl;
}

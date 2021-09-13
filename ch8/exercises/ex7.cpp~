// ex7.cpp -- extension of tempover.cpp
#include <iostream>
#include <cstring>
using namespace std;


struct debts
{
    char name[50];
    double amount;
};
template <typename T> // template A
void ShowArray(T arr[], int n);

template <typename T> // template B
void ShowArray(T *arr[], int n);

template <typename T>
T SumArray(T arr[], int n);

template <> debts SumArray(debts arr[], int n);
int main()
{
    int things[6] = {13, 31, 103, 301, 310, 130};
    debts mr_E[3] =
    {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0},
    };
    double * pd[3];

    // set pointers to the amount members of the structures in mr_E
    for (int i = 0; i < 3; ++i)
        pd[i] = &mr_E[i].amount;

    cout << "Listing Mr. E's counts of things:\n";
    // things is an array of int
    ShowArray(things, 6); // uses template A
    cout << "Listing Mr.E;s debts:\n";
    // pd is an array of pointers to double
    ShowArray(pd, 3); // uses template B
    cout << "The sum of things: " << SumArray(things, 6) << endl;
    debts sum_debts = SumArray(mr_E, 3);
    cout << "The sum of debts: " << sum_debts.amount << endl;

    return 0;
}

template <typename T>
void ShowArray(T arr[], int n)
{
    cout << "template A\n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << ' ';
    cout << endl;
}

template <typename T>
void ShowArray(T *arr[], int n)
{
    cout << "template B\n";
    for (int i = 0; i < n; ++i)
        cout << *arr[i] << ' ';
    cout << endl;
}

template <typename T>
T SumArray(T arr[], int n)
{
    T sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    return sum;
}

template <> debts SumArray(debts arr[], int n)
{
    debts sum = {"", 0.0};
    for (int i = 0; i < n; ++i) {
        strcat(sum.name, ", ");
        strcat(sum.name, arr[i].name);
        sum.amount += arr[i].amount;
    }
    return sum;
}

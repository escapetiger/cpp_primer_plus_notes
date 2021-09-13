/******************************************************************************
* File:             workermi.cpp
*
* Author:           Joey Tsai
* Created:          09/04/21
* Description:      multiple inheritance
*****************************************************************************/
#include <iostream>
#include "workermi.h"
using std::cout;
using std::cin;
using std::endl;

// Worker methods
Worker::~Worker() {};

// protected methods
void Worker::Data() const
{
    cout << "Name: " << fullname << endl;
    cout << "Employee ID: " << id << endl;
}

void Worker::Get()
{
    getline(cin, fullname);
    cout << "Enter worker's ID: ";
    cin >> id;
    while (cin.get() != '\n')
        continue;
}

// Waiter methods
// protected methods
void Waiter::Data() const
{
    cout << "Panache rating: " << panache << endl;
}

void Waiter::Get()
{
    cout << "Enter waiter's panache rating: ";
    cin >> panache;
    while ( cin.get() != '\n' )
        continue;
}


void Waiter::Set()
{
    cout << "Enter waiter's name: ";
    Worker::Get();
    Get();
}

void Waiter::Show() const
{
    cout << "Categort: waiter\n";
    Worker::Data();
    Data();
}

// Singer methods
const char * Singer::pv[] = {"other", "alto", "contaralto", "soprano", "bass", "baritone", "tenor"};

// protected methods
void Singer::Data() const
{
    cout << "Vocal range: " << pv[voice] << endl;
}

void Singer::Get()
{
    cout << "Enter number for singer's vocal range:\n";
    int i;
    for (i = 0; i < Vtypes; ++i)
    {
        cout << i << ": " << pv[i] << "   ";
        if (i % 4 == 3)
            cout << endl;
    }
    if (i % 4 != 0)
        cout << endl;
    while (cin >> voice && (voice < 0 || voice > Vtypes))
        cout << "Please enter a vlaue >=0 and < " << Vtypes << endl;

    while (cin.get() != '\n')
        continue;
}

void Singer::Set()
{
    cout << "Enter singer's name: ";
    Worker::Get();
    Get();
}

void Singer::Show() const
{
    cout << "Category: singer\n";
    Worker::Data();
    Data();
}

// SingingWaiter methods
// protected methods
void SingingWaiter::Data() const
{
    Singer::Data();
    Waiter::Data();
}

void SingingWaiter::Get()
{
    Singer::Get();
    Waiter::Get();
}

void SingingWaiter::Set()
{
    cout << "Enter singing waiter's name: ";
    Worker::Get();
    Get();
}

void SingingWaiter::Show() const
{
    cout << "Category: singing waiter\n";
    Worker::Data();
    Data();
}

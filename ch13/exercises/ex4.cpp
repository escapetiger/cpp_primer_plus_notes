/******************************************************************************
* File:             ex4.cpp
*
* Author:           Joey Tsai  
* Created:          09/02/21 
* Description:      use Port and VintagePort class;
*                   compiled with port.cpp and vport.cpp
*****************************************************************************/

#include <iostream>
#include "vport.h"

int main(void)
{
    using std::cout;
    using std::endl;

    Port p1("Gallo", "tawny", 20);
    VintagePort p2("Newton", 30, "NT", 5);
    Port * pp1 = &p1;

    cout << "Using object directly:\n";
    cout << "Display by Show():\n";
    p1.Show();
    p2.Show();
    cout << endl;
    cout << "Display by << operator:\n";
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << endl;

    cout << "Using type Port * pointer to objects:\n";
    cout << "*pp1: " << *pp1 << endl;
    cout << endl;

    cout << "Using Port reference:\n";
    Port & p3 = p2;               // type cast from VintagePort to Port
    cout << "p3: " << p3 << endl; // call Port::operator<<
    cout << endl;

    cout << "Testing assignment:\n";
    VintagePort cp;
    cp = p2;
    cout << "cp: " << cp << endl;
    cout << endl;
    return 0;
}

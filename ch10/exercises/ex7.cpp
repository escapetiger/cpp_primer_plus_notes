// ex7.cpp -- use Plorg class
// compiled with plorg.cpp
#include <iostream>
#include "plorg.h"

int main()
{
    using namespace std;
    Plorg plg1("Betelgeusean", 10);
    Plorg plg2("Cai Yi");
    Plorg plg3;
    cout << "Info of plg1: ";
    plg1.show();
    cout << "Info of plg2: ";
    plg2.show();
    cout << "Info of plg3: ";
    plg3.show();
    plg3.reset(100);
    cout << "Current info of plg3: ";
    plg3.show();
    
    return 0;
}

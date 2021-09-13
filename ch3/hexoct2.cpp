// hexoct.cpp -- display values in hex and octal literals
#include <iostream>
using namespace std;

int main()
{
    int chest = 42;
    int waist = 42;
    int inseam = 42;

    cout << "Monsieur cuts a striking figure\n";
    cout << "chest = " << chest << " (42 in decimal)\n";
    cout << hex;                                          // manipulator for changing number base
    cout << "waist = " << waist << " (0x42 in hex)\n";
    cout << oct;                                          // manipulator for changing number base
    cout << "inseam = " << inseam << " (042 in octal)\n";
    return 0;
}

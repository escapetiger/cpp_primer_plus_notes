// twofile2.cpp -- variables with internal and external linkage
#include <iostream>
extern int tom;       // tom defined else where
static int dick = 10; // overrides exetrnal dick
int harry = 200;      // external variable definition,
                      // no conflict with two file1 harry
void remote_access(){
    using namespace std;
    cout << "remote_access reports the following addresses:\n";
    cout << &tom << " = &tom, " << &dick << " = &dick, ";
    cout << &harry << " = &harry\n";
}

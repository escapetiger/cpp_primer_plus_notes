// inline.cpp -- using an inline function 
#include <iostream>
using namespace std;
// an inline function definition
inline double square(double x) { return x * x; }

int main()
{
    double a = 0.0, b = 0.0;
    double c = 13.0;
    
    a = square(5.0);
    b = square(4.5 + 7.5);
    cout << "a = " << a << ", b = " << b << "\n";
    cout << "c = " << c;
    cout << ", c squared = " << square(c++) << "\n";
    cout << "Now c = " << c << "\n";
    
    return 0;
}

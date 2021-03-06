// divide.cpp -- integer and floating-point division
#include <iostream>
int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    std::cout << "Integer division: 9/5 = " << 9 / 5 << std::endl;
    std::cout << "Floating-point division: 9.0/5.0 = " << 9.0 / 5.0 << std::endl;
    std::cout << "Mixed division: 9.0/5 = " << 9.0 / 5 << std::endl;
    std::cout << "double constants: 1e7/9.0 = " << 1.e7 / 9.0 << std::endl;
    std::cout << "float constants: 1e7f/9.0f = " << 1.e7f / 9.0f << std::endl;

    return 0;
}

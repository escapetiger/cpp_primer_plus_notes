#include <iostream>
using namespace std;

int main()
{
    int a, b;
    int sum = 0;
    std::cout << "Enter two integers a, b:(a<b)\n";
    std::cin >> a >> b;
    for (int i = a; i <= b; i++) {
       sum += i;
    }
    std::cout << "The sum of all integers between a and b is: "<< sum << "\n";
    return 0;
}

// ex5.cpp -- factorial
#include <iostream>
using namespace std;
// prototypes
unsigned int Factorial(int n);

int main()
{
    int n;
    cout << "Enter a natural number: ";
    cin >> n;
    cout << n << "!: " << Factorial(n) << endl;

    return 0;
}

unsigned int Factorial(int n)
{
    if (n == 0) return 1;
    return n * Factorial(n - 1);
}

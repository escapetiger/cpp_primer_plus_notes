// ex1.cpp -- harmonic mean
#include <iostream>
using namespace std;
// prototypes
double HarmonicMean(double a, double b);

int main()
{
    double num1 = 0.0, num2 = 0.0;
    cout << "Enter two numbers: ";
    while (cin >> num1 >> num2)
    {
        cout << "The harmonic mean: " << HarmonicMean(num1, num2) << endl;
        cout << "Enter another two numbers (q to quit): ";
    }
    return 0;
}

double HarmonicMean(double a, double b)
{
    return (2.0 * a * b) / (a + b);
}

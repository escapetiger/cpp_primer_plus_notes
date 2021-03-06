// ex10.cpp -- basic operations
#include <iostream>
using namespace std;
// prototypes
double Add(double x, double y);
double Multiply(double x, double y);
double Minus(double x, double y);

typedef double (*opt)(double, double);
double calculate(double x, double y, opt op);

int main()
{
    int x = 0, y = 0;
    cout << "Enter two numbers (x and y): ";
    while (cin >> x >> y)
    {
        cout << "The sum of x and y: " << calculate(x, y, Add) << endl;
        cout << "The product of x and y: " << calculate(x, y, Multiply) << endl;
        cout << "The difference of x and y: " << calculate(x, y, Minus) << endl;
        cout << "Enter two numbers (x and y): ";
    }

    return 0;
}

double calculate(double x, double y, opt op)
{
    return (*op)(x, y);
}

double Add(double x, double y)
{
    return x + y;
}

double Multiply(double x, double y)
{
    return x * y;
}

double Minus(double x, double y)
{
    return x - y;
}

// ex2.cpp -- more random walk
// compiled with the vector1.cpp file
#include <iostream>
#include <cstdlib> // rand(), srand() prototypes
#include <ctime> // time() prototype
#include <fstream>
#include <ostream>
#include "limits.h" 
#include "vector1.h"

void print(std::ostream & os, VECTOR::Vector & res, double steps);
unsigned long test(double target, double dstep);

int main()
{
    using namespace std;
    using VECTOR::Vector;

    srand(time(0));       // seed random-number generator
    double target;
    double dstep;
    int N;

    cout << "Enter target distance: ";
    while (!(cin >> target)) cout << "Wrong input for taget distance!";
    cout << "Enter step length: ";
    while (!(cin >> dstep)) cout << "Wrong input for step length!";
    cout << "Enter times you want to test: ";
    while (!(cin >> N)) cout << "Wrong input for times!";

    cout << "Target Distane: " << target << ", "
         << "Step Size: " << dstep << endl;

    double ave, total = 0.0;
    unsigned long steps = 0.0;
    unsigned long max = 0, min = ULONG_MAX;
    for (int i = 0; i < N; ++i) {
        steps = test(target, dstep);
        max = std::max(max, steps);
        min = std::min(min, steps);
        total += steps;
    }
    ave = total / N;

    cout << "The number of steps is in [" << min << ", " << max << "].\n";
    cout << "The average number of steps is " << ave << endl;

    cout << "Bye!\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;

    return 0;
}

void print(std::ostream & os, VECTOR::Vector & res, double steps)
{
    using std::endl;
    os << "After " << steps << " steps, the object "
       "has the following location:\n";
    os << res << endl;
    res.polar_mode();
    os << " or\n" << res << endl;
    os << "Average outward distance per step = "
       << res.magval() / steps << endl;
}

unsigned long test(double target, double dstep)
{
    using VECTOR::Vector;
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0.0;
 
    while (result.magval() < target)
    {
        direction = rand() % 360;
        step.reset(dstep, direction, Vector::POL);
        result = result + step;
        steps++;
    }
    return steps;
}

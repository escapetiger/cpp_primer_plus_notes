// ex2.cpp -- more random walk
// compiled with the vector1.cpp file
#include <iostream>
#include <cstdlib> // rand(), srand() prototypes
#include <ctime> // time() prototype
#include <fstream>
#include <ostream>
#include "vector1.h"

void print(std::ostream & os, VECTOR::Vector & res, double steps);
int main()
{
    using namespace std;
    using VECTOR::Vector;

    std::ofstream fout;   // create a new os object
    fout.open("ex2.out"); // bind with the file ex1.out

    srand(time(0));       // seed random-number generator
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0.0;
    double target;
    double dstep;
    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;
        fout << "Target Distane: " << target << ", "
             << "Step Size: " << dstep << endl;

        while (result.magval() < target)
        {
            fout << steps << ": " << result << endl;
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
        }
        print(fout, result, steps);
        print(cout, result, steps);
       steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }
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

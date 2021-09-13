// external.cpp -- external variables
// compile with support.cpp
#include <iostream>
using namespace std;
// external variable
double warming = 0.3; // warming defined
// function prototypes
void update(double dt);
void local();

int main() // use global variable
{
    cout << "Global warming is " << warming << " degree.\n";
    update(0.1);
    cout << "Global warming is " << warming << " degree.\n";
    local();
    cout << "Global warming is " << warming << " degree.\n";
    
    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    double Cleo = 100, Daphne = 100;
    int count = 0;
    while (Cleo <= Daphne)
    {
        Cleo = Cleo * 1.05;
        Daphne = Daphne + 10;
        ++count;
    }
    cout << "After " << count << " years, "
         << "Cleo has " << Cleo
         << " and Daphne has " << Daphne << ".\n";
    return 0;
}

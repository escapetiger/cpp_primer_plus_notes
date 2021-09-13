// ex5.cpp -- tax computation
#include <iostream>
using namespace std;

int main()
{

    double income = 0.0, tax = 0.0;
    cout << "Enter your income: ";
    while (cin >> income)
    {
        if (income < 5000)
            tax = 0.0;
        else if (income < 15000 && income > 5000)
            tax = (income - 5000) * 0.1;
        else if (income < 35000 && income > 15000)
            tax = (income - 15000) * 0.15 + 1000;
        else if (income > 35000)
            tax = (income - 35000) * 0.2 + 4000;
        cout << "You need to pay " << tax << " for tax." << endl;
        cout << "Enter your income again: ";
    }
    cout << "Bye!" << endl;
    return 0;
}

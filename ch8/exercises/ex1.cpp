// ex1.cpp -- print strings
#include <iostream>
#include <string>
using namespace std;

void Show(const string *str);
void Show(const string *str, int n);

int main()
{
    string str;
    int times;
    cout << "Enter a string: ";
    getline(cin, str);
    Show(&str);
    cout << "Enter times you want to print: ";
    cin >> times;
    Show(&str, times);

    return 0;
}

void Show(const string *str)
{
    cout << "You have entered: " << *str << endl;
}

void Show(const string *str, int n)
{
    cout << *str << endl;
    if (n == 0)
        return;
    else
        Show(str, n - 1);
}

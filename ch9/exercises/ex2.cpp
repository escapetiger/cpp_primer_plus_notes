// ex2.cpp -- extension of static.cpp
#include <iostream>
#include <string>
// function prototype
void strcount(const std::string str);
int main()
{
    using namespace std;
    string input;

    cout << "Enter a line:\n";
    getline(cin, input);
    while (cin)
    {
        if(input == "") break;
        strcount(input);
        cout << "Enter next line (empty line to quit):\n";
        getline(cin, input);
    }
    cout << "Bye\n";
    return 0;
}

void strcount(const std::string str)
{
    using namespace std;
    static int total = 0;                   // static local varaible
    int count = str.size();                 // automatic local variable

    total += count;
    cout << "\"" << str << "\" contains ";
    cout << count << " characters\n";
    cout << total << " characters total\n";
}

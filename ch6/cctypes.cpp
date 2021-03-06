// cctypes.cpp -- using the ctype.h library
#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    cout << "Enter text for analysis, and type @"
         " to terminate input.\n";
    char ch;
    int whitespace = 0, digits = 0, chars = 0, punct = 0, others = 0;
    cin.get(ch);
    while (ch != '@')
    {
        if (isalpha(ch))
            chars++;
        else if (isspace(ch))
            whitespace++;
        else if (isdigit(ch))
            digits++;
        else if (ispunct(ch))
            punct++;
        else
            others++;
        cin.get(ch);
    }
    cout << chars << " letters, "
         << whitespace << " whitespace, "
         << digits << " digits, "
         << punct << " punctuations, "
         << others << " others.\n";
    return 0;
}

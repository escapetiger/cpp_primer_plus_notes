/******************************************************************************
* File:             ex2.cpp
*
* Author:           Joey Tsai
* Created:          09/06/21
* Description:      panlindrome string (ignore case)
*****************************************************************************/

#include <iostream>
#include <string>
#include <cctype>
using std::string;

char toLower(char ch);
bool IsPanlindrome(const string & s);
int main(void)
{
    using std::cout;
    using std::cin;
    using std::endl;
    string s;
    cout << "Please enter a string <q to quit>: ";
    getline(cin, s);
    while (s != "q")
    {
        if (IsPanlindrome(s))
            cout << s << " is a panlindrome!\n";
        else
            cout << s << " is not a panlindrome!\n";
        cout << "Please enter a string <q to quit>: ";
        getline(cin, s);
    }

    cout << "Bye.\n";
    return 0;
}

char toLower(char ch)
{
    return tolower(ch);
}

bool IsPanlindrome(const string & s)
{
    int i = 0;
    int j = s.size() - 1;
    while (i < j)
    {
        while (!isalpha(s[i])) i++;
        while (!isalpha(s[j])) j--;
        if (toLower(s[i]) == toLower(s[j]))
            i++, j--;
        else
            return false;
    }
    return true;
}

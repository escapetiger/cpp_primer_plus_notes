/******************************************************************************
* File:             ex1.cpp
*
* Author:           Joey Tsai
* Created:          09/06/21
* Description:      panlindrome string
*****************************************************************************/

#include <iostream>
#include <string>
using std::string;

bool IsPanlindrome(const string & s);
int main(void)
{
    using std::cout;
    using std::cin;
    using std::endl;
    string s;
    cout << "Please enter a string <q to quit>: ";
    while (cin >> s && s != "q")
    {
        if (IsPanlindrome(s))
            cout << s << " is a panlindrome!\n";
        else
            cout << s << " is not a panlindrome!\n";
        cout << "Please enter a string <q to quit>: ";
    }

    cout << "Bye.\n";
    return 0;
}

bool IsPanlindrome(const string & s)
{
    int len = s.size();
    for (int i = 0; i < len / 2; ++i)
        if (s[i] != s[len - i - 1])
            return false;
    return true;
}

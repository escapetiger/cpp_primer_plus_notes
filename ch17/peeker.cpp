/******************************************************************************
* File:             peeker.cpp
*
* Author:           Joey Tsai
* Created:          09/07/21
* Description:      some istream methods
*****************************************************************************/

#include <iostream>
int main(void)
{
    using std::cout;
    using std::cin;
    using std::endl;

    // read and echo input up to a # character
    char ch;
    while (cin.get(ch))
    {
        if (ch != '#')
            cout << ch;
        else
        {
            cin.putback(ch);
            break;
        }
    }

    if (!cin.eof())
    {
        cin.get(ch);
        cout << endl << ch << " is next input character.\n";
    }
    else
    {
        cout << "End of file reached.\n";
        std::exit(0);
    }

    while (cin.peek() != '#')
    {
        cin.get(ch);
        cout << ch;
    }
    if (!cin.eof())
    {
        cin.get(ch);
        cout << endl << ch << " is next input character.\n";
    }
    else
    {
        cout << "End of file reached.\n";
        std::exit(0);
    }

    return 0;
}

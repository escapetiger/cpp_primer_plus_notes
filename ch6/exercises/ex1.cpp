// ex1.cpp -- read keyboard input until @, and show the input on the screen.
//         -- at the same time, exchange the upper letters and lower letters.
#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char ch = 'a';
    cout << "Enter some text here (press @ to terminate):\n";
    while (cin.get(ch) && ch != '@')
    {
        if (isdigit(ch))
            continue;
        else
        {
            if ((ch >= 'a') && (ch <= 'z'))
                cout << (char) toupper(ch);
            else if ((ch >= 'A') && (ch <= 'Z'))
                cout << (char) tolower(ch);
            else
                cout << ch;
        }
    }
    cout << "Bye!" << endl;
    return 0;
}

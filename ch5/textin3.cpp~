// textin3.cpp -- reading chars with a while loop
#include <iostream>
int main(void)
{
    using namespace std;
    char ch;
    int count = 0;                                  // use basic input
    cin.get(ch);                                    // get a character
    while (cin.fail() == false)                     // test for EOF
    {
        cout << ch;                                 // echo the character
        ++count;                                    // count the character
        cin.get(ch);                                // get the next character
    }
    cout << endl << count << " characters read\n";
    return 0;
}

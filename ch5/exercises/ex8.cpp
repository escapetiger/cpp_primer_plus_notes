#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char word[20];
    int wordNum = 0;
    cout << "Enter words (to stop, type the word done):\n";
    while (cin >> word) // continously enter word
    {
        if (!strcmp(word, "done"))
            break;
        else
            ++wordNum;
    }
    cout << "You entered a total of " << wordNum << " words." << endl;
}

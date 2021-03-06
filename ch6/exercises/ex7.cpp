// ex7.cpp -- word count
#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main()
{
    string word;
    int vowelCount = 0, consonantCount = 0, otherCount = 0;
    cout << "Enter a word (q to quit):\n";
    while (cin >> word && word != "q")
    {
        if (isalpha(word[0]))
        {
            switch (word[0])
            {
            case 'a':
            case 'o':
            case 'u':
            case 'e':
            case 'i':
                ++vowelCount;
                break;
            default:
                ++consonantCount;
            }
        }
        else
            ++otherCount;

    }
    cout << vowelCount << " words beginning with vowels\n";
    cout << consonantCount << " words beginning with consonants\n";
    cout << otherCount << " others" << endl;
    return 0;
}

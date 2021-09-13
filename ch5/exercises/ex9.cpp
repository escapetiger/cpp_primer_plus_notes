#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Enter words (to stop, type the word done):\n";
    int wordNum = 0;
    for (string word; word != "done"; ++wordNum) 
        cin >> word;
    cout << "You entered a total of " << wordNum - 1 << " words." << endl;
    return 0;
}

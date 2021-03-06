/******************************************************************************
* File:             vect1.cpp
*
* Author:           Joey Tsai
* Created:          09/06/21
* Description:      introducing the vector template
*****************************************************************************/

#include <iostream>
#include <string>
#include <vector>

const int NUM = 5;
int main(void)
{
    using std::vector;
    using std::string;
    using std::cin;
    using std::cout;
    using std::endl;

    vector<int> ratings(NUM);
    vector<string> titles(NUM);
    cout << "YOu will do exactly as told. You will enter\n"
         << NUM << "book titles and your ratings (0-10).\n";
    for (int i = 0; i < NUM; ++i)
    {
        cout << "Enter title #" << i + 1 << ": ";
        std::getline(cin, titles[i]);
        cout << "Enter your rating (0-10): ";
        cin >> ratings[i];
        cin.get();
    }
    cout << "Thank you. You entered the following:\n"
         << "Rating\tBook\n";
    for (int i = 0; i < NUM; ++i)
        cout << ratings[i] << "\t" << titles[i] << endl;

    return 0;
}

/******************************************************************************
* File:             ex7.cpp
*
* Author:           Joey Tsai
* Created:          09/07/21
* Description:      lotto
*****************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

vector<int> Lotto(int tot, int choice);

int main(void)
{
    vector<int> winners;
    winners = Lotto(51, 6);
    cout << "People holding cards with the following numbers are winners!\n";
    for (auto w : winners)
        cout << w << ' ';
    cout << endl;

    return 0;
}

vector<int> Lotto(int tot, int choice)
{
    srand(time(0));
    vector<int> ivec;
    for (int i = 0; i < tot; ++i)
        ivec.push_back(i + 1);

    vector<int> winners;
    for (int i = 0; i < choice; ++i)
    {
        random_shuffle(ivec.begin(), ivec.end());
        while (i > 0 && find(winners.begin(), winners.end(), ivec.front()) != winners.end())
            random_shuffle(ivec.begin(), ivec.end());

        winners.push_back(ivec.front());
    }

    return winners;
}

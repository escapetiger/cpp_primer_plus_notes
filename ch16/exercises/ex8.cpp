/******************************************************************************
* File:             ex8.cpp
*
* Author:           Joey
* Created:          09/07/21
* Description:      union of name lists
*****************************************************************************/

#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    set<string> mfrnd;
    set<string> pfrnd;
    string stmp;
    cout << "Enter name list of Mat's friends <q to quit>:\n";
    getline(cin, stmp);
    while (stmp != "q")
    {
        mfrnd.insert(stmp);
        cout << " Another one <q to quit>:\n";
        getline(cin, stmp);
    }

    cout << "Enter name list of Pat's friends <q to quit>:\n";
    getline(cin, stmp);
    while (stmp != "q")
    {
        pfrnd.insert(stmp);
        cout << " Another one <q to quit>:\n";
        getline(cin, stmp);
    }


    std::ostream_iterator<string, char> out_iter(cout, ", ");
    cout << "Mat's friends: ";
    copy(mfrnd.begin(), mfrnd.end(), out_iter);
    cout << endl;
    cout << "Pat's friends: ";
    copy(pfrnd.begin(), pfrnd.end(), out_iter);
    cout << endl;

    set<string> frnd;
    set_union(mfrnd.begin(), mfrnd.end(), pfrnd.begin(), pfrnd.end(),
              insert_iterator<set<string>> (frnd, frnd.begin()));
    cout << "The whole friends: ";
    copy(frnd.begin(), frnd.end(), out_iter);
    cout << endl;

    return 0;
}


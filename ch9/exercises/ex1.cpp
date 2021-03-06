#include <iostream>
#include <cstring>
#include "golf.h"
using namespace std;
const int SLEN = 20;
const int GLEN = 3;

int main()
{
    golf glist[GLEN];
    char name[SLEN];
    int i = 0, hc = 0;
    cout << "Golf #1" << endl;
    while (i < GLEN)
    {
        cout << "Name: ";
        cin.getline(name, SLEN);
        if (!std::strcmp(name, ""))
            break;
        cout << "Handicap: ";
        cin >> hc;
        cin.clear();
        while(cin.get() != '\n' ) continue;
        setgolf(glist[i++], name, hc);
        cout << "Golf #" << i + 1 << endl;
    }
    for (int j = 0; j < i; ++j) {
        showgolf(glist[j]);
    }

    return 0;
}

/******************************************************************************
* File:             ex3.cpp
*
* Author:           Joey Tsai
* Created:          09/06/21
* Description:      read strings from a file
*****************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

int main(void)
{
    using namespace std;
    ifstream fin;
    fin.open("tobuy.txt");
    if (fin.is_open() == false)
    {
        cerr << "Can't open file. Bye.\n";
        exit(EXIT_FAILURE);
    }
    vector<string> svec;
    string s;
    while (fin >> s)
        svec.push_back(s);

    cout << "Length of svec: " << svec.size() << endl;
    cout << "svec: ";
    for (auto s : svec)
        cout << s << " ";
    cout << endl;

    cout << "Done\n";
    fin.close();
    return 0;
}

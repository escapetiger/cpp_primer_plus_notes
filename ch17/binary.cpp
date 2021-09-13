/******************************************************************************
* File:             binary.cpp
*
* Author:           Joey Tsai
* Created:          09/07/21
* Description:      binary file I/O
*****************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

inline void eatline()
{
    while (std::cin.get() != '\n') continue;
}
struct planet
{
    char name[20];     // name of planet
    double population; // its population
    double g;          // its accerleration
};

const char * file = "planets.dat";
int main(void)
{
    using namespace std;
    planet pl;
    cout << fixed << right;
    // show initial contents
    ifstream fin;
    fin.open(file, ios_base::in | ios_base::binary); // binary file

    if (fin.is_open())
    {
        cout << "Here are current contents of the "
             << file << " file:\n";
        while (fin.read((char *)  &pl, sizeof pl))
        {
            cout << setw(20) << pl.name << ": "
                 << setprecision(0) << setw(12) << pl.population
                 << setprecision(2) << setw(6) << pl.g << endl;
        }
        fin.close();
    }

    // add new data
    ofstream fout(file, ios_base::out | ios_base::app | ios_base::binary);
    if (!fout.is_open())
    {
        cerr << "Can't open " << file << " file for output:\n";
        exit(EXIT_FAILURE);
    }

    cout << "Enter planet name (enter a blank line to quit):\n";
    cin.get(pl.name, 20);
    while (pl.name[0] != '\0' )
    {
        eatline();
        cout << "ENter planetary popluation: ";
        cin >> pl.population;
        cout << "Enter planet's accerleration of gravity: ";
        cin >> pl.g;
        eatline();
        fout.write((char *) &pl, sizeof pl);
        cout << "Enter planet name (enter a blank line to quit):\n";
        cin.get(pl.name, 20);
    }
    fout.close();

    // show revised file
    fin.clear();
    fin.open(file, ios_base::in | ios_base::binary);
    if (fin.is_open())
    {
        cout << "Here are the new contents of the "
             << file << " file:\n";
        while (fin.read((char *)  &pl, sizeof pl))
        {
            cout << setw(20) << pl.name << ": "
                 << setprecision(0) << setw(12) << pl.population
                 << setprecision(2) << setw(6) << pl.g << endl;
        }
        fin.close();
    }

    cout << "Done.\n";

    return 0;
}

// ex9.cpp -- record program
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct donater
{
    string name;
    double donation;
};
int main()
{
    ifstream fin;
    string filename = "ex9.in";
    fin.open("ex9.in");
    if (!fin.is_open())   // check whether link successfully
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Porgram terminating.\n";
        exit(EXIT_FAILURE);
    }

    int donaterNum = 0;
    fin >> donaterNum;
    donater *dntList = new donater[donaterNum];
    // 1. Read data
    for (int i = 0; i < donaterNum; ++i)
    {
        fin.get(); // clear '\n' in the head of line
        getline(fin, dntList[i].name);
        fin >> dntList[i].donation;
    }

    // 2. show Grand Patrons
    int count = 0;
    cout << "Grand Patrons:\n";
    for (int i = 0; i < donaterNum; ++i)
        if (dntList[i].donation > 10000)
        {
            ++count;
            cout << dntList[i].name << "\t" << dntList[i].donation << endl;
        }
    if (count == 0)
        cout << "none" << endl;

    // 3. show others
    cout << "Patrons:\n";
    for (int i = 0; i < donaterNum; ++i)
        if (dntList[i].donation <= 10000)
        {
            ++count;
            cout << dntList[i].name << "\t" << dntList[i].donation << endl;
        }
    if (count == 0)
        cout << "none" << endl;

    return 0;
}

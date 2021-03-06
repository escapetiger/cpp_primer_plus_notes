// ex6.cpp -- record program
#include <iostream>
#include <string>
using namespace std;
struct donater
{
    string name;
    double donation;
};
int main()
{
    int donaterNum = 0;
    cout << "How many donaters? ";
    cin >> donaterNum;
    donater *dntList = new donater[donaterNum];
    // 1. Read data
    cout << "Enter personal information of the first donater:\n";
    for (int i = 0; i < donaterNum; ++i)
    {
        cin.get(); // clear '\n' in the head of line
        cout << "Enter his/her name: ";
        getline(cin, dntList[i].name);
        cout << "Enter his/her donatertion: ";
        cin >> dntList[i].donation;
        cout << "Enter personal information of another donater:\n";
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

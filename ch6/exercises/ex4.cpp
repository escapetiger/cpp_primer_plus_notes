// ex5.cpp -- a query system
#include <iostream>
using namespace std;
const int strsize = 30;
const int bopNum = 5;
// Benevolent Order of Programmers name structure
struct bop
{
    char fullname[strsize]; // real name
    char title[strsize]; // job title
    char bopname[strsize]; // secret BOP name
    int preference; // 0 = fullname, 1 = title, 2 = bopname
};

int main()
{
    char choice;
    bop bopList[bopNum] =
    {
        {"Winp Macho", "Professor", "MIP", 1},
        {"Raki Rhodes", "Asscociate Professor", "ANP", 0},
        {"Celia Laiter", "Professor", "KKK", 1},
        {"Hoppy Hipman", "Professor", "Jr", 2},
        {"Pat Hand", "Junior Programmer", "PH", 0},
    };
    cout << "Benevolent Order of Programmers Report\n"
         "a. display by name    \tb.display by title\n"
         "c. display by bop name\td.display by preference\n"
         "q. quit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    bool flag = true;
    while (flag)
    {
        flag = false;
        switch (choice)
        {
        case 'a':
            for (int i = 0; i < bopNum; ++i)
                cout << bopList[i].fullname << endl;
            break;
        case 'b':
            for (int i = 0; i < bopNum; ++i)
                cout << bopList[i].title << endl;
            break;
        case 'c':
            for (int i = 0; i < bopNum; ++i)
                cout << bopList[i].bopname << endl;
            break;
        case 'd':
            for (int i = 0; i < bopNum; ++i)
            {
                switch (bopList[i].preference)
                {
                case 0:
                    cout << bopList[i].fullname << endl;
                    break;
                case 1:
                    cout << bopList[i].title << endl;
                    break;
                case 2:
                    cout << bopList[i].bopname << endl;
                    break;
                }
            }
            break;
        case 'q':
            flag = false;
            cout << "Bye!" << endl;
            break;
        }
        if (flag)
        {

            cout << "Next choice: ";
            cin >> choice;
        }
    }
    return 0;
}

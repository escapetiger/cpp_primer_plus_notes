// ex3.cpp -- a menu application
#include <iostream>
#include <string>
using namespace std;

int main()
{
    char choice;
    cout << "Please enter one of the following choices:\n"
         "c) carnivore\tp) pianist\n"
         "t) tree     \tg) game\n";
    bool flag = true;
    while (flag)
    {
        flag = false;
        cin >> choice;
        switch (choice)
        {
        case 'c':
            cout << "You choose a carnivore." << endl;
            break;
        case 'p':
            cout << "You choose a pianist." << endl;
            break;
        case 't':
            cout << "You choose a tree." << endl;
            break;
        case 'g':
            cout << "You choose a game." << endl;
            break;
        default:
            flag = true;
            cout << "Please enter a c, p, t, or g: ";
        }
    }
    return 0;
}

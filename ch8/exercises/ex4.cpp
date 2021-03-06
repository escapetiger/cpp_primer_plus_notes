// ex4.cpp -- stringy
#include <iostream>
using namespace std;
#include <cstring> // for strlen(), strcpy()
struct stringy
{
    char *str; // points to a string
    int ct; // length of string (not counting '\0')
};

// prototypes for set(), show(), and show() go here
void set(stringy &stry, char *str);
void show(const stringy &stry, int n = 1);
void show(const char *str, int n = 1);

int main()
{
    stringy beany;
    char testing[] = "reality isn't what it used to be.";

    set(beany, testing);
    show(beany);
    show(beany, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done!");
    return 0;
}

void set(stringy &stry, char *str)
{
    stry.str = new char[strlen(str) + 1]; // Must allocate enough space for stry.str!!!
    strcpy(stry.str, str);
    stry.ct = strlen(str);
}

void show(const stringy &stry, int n)
{
    for (int i = 0; i < n; ++i)
        cout << stry.str << endl;
}

void show(const char *str, int n)
{
    for (int i = 0; i < n; ++i){
        cout << *str << endl;
    }
}

// ex8.cpp -- file input and count its characters
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream fin; // create my ifstream object
    string filename;
    cout << "Enter the name of file you want to read: ";
    cin >> filename;
    fin.open(filename); // link to target file
    if (!fin.is_open())   // check whether link successfully
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Porgram terminating.\n";
        exit(EXIT_FAILURE);
    }

    int count = 0;
    char ch;
    while (fin.get(ch))
        ++count;

    cout << "The file contains " << count << " characters.\n";

    return 0;
}

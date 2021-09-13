#include <iostream>
#include <string>
int main(void)
{
    using namespace std;
    string firstName;
    string lastName;
    string name;
    cout << "Enter your first name: ";
    cin >> firstName;
    cout << "Enter your last name: ";
    cin >> lastName;
    name += lastName;
    name += ", ";
    name += firstName;
    cout << "Here's the information in a single string: " << name << endl;
    return 0;
}

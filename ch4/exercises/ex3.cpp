#include <iostream>
#include <cstring>
int main(void)
{
    using namespace std;
    char firstName[20];
    char lastName[20];
    char name[40];
    cout << "Enter your first name: ";
    cin >> firstName;
    cout << "Enter your last name: ";
    cin >> lastName;
    strcpy(name, lastName);
    strcat(name, ", ");
    strcat(name, firstName);
    cout << "Here's the information in a single string: " << name << endl;
    return 0;
}

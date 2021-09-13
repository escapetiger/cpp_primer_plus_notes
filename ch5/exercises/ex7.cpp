#include <iostream>
#include <string>
using namespace std;
struct car
{
    string make;
    int year;
};
int main()
{
    int carNum;
    cout << "How many car do you wishto catalog? ";
    cin >> carNum;
    car *cars = new car[carNum];
    for (int i = 0; i < carNum; ++i)
    {
        cout << "Car #" << i + 1 << ":\n";
        cout << "Please enter the make: ";
        cin.get();                              // NOTE: clear remaining '\n'
        getline(cin, cars[i].make);             // getline() for make
        cout << "Please enter the year made: ";
        cin >> cars[i].year;
        cout << endl;
    }

    cout << "Here is your collection:\n";
    for (int i = 0 ; i < carNum; ++i)
    {
        cout << cars[i].year << "\t" << cars[i].make << "\n";
    }
    cout << endl;
    return 0;
}

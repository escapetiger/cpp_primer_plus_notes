#include <iostream>
#include <string>
using namespace std;

int main()
{
    int total_num = 0;
    int record[12];
    cout << "Enter sales volume in each month:\n";
    for (int i = 0; i < 12; ++i) {
        cin >> record[i];
        total_num += record[i];
    }
    string month[12] = {
        "January", "Febrary", "March", "April",
        "May", "June", "July", "August", "September",
        "October", "November", "December"
    };
    cout << "The annual sale:\n";
    for (int i = 0; i < 12; ++i) {
        cout << month[i] << ": " << record[i] << "\n";
    }
    cout << "The total sales: " << total_num << endl;
    return 0;
}

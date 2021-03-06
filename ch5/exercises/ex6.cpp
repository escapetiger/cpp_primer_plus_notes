#include <iostream>
#include <string>
#include <array>
using namespace std;

int main()
{
    int total_num = 0;
    std::array<std::array<int, 12>, 3> record;
    cout << "Enter sales volume in each month:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 12; ++j) {
            cin >> record[i][j];
            total_num += record[i][j];
        }
    }
    string month[12] = {
        "January", "Febrary", "March", "April",
        "May", "June", "July", "August", "September",
        "October", "November", "December"
    };
    cout << "The annual sale:\n";
    for (int i = 0; i < 3; ++i) {
        cout << "\n" << "Sales in Year " << i << ":\n";
        for (int j = 0; j < 12; ++j) {
            cout << month[j] << "     \t" << record[i][j] << "\n";
        }
    }
    cout << "The total sales: " << total_num << endl;
    return 0;
}

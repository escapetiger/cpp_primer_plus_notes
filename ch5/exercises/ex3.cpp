#include <iostream>
using namespace std;

int main()
{
    int num, sum = 0;
    cout << "Enter a number:(press 0 to quit)\n";
    cin >> num;
    while (num != 0) {
        sum += num;
        cout << "Accumlate Sum: "<< sum << endl;
        cin >> num;
    }
    cout << "Done.\n";
    return 0;
}

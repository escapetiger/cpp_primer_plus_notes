// ex2.cpp -- read donation into a double array
#include <iostream>
using namespace std;
const int MAX = 10;

int main()
{
    double donations[MAX];
    double total = 0.0, ave = 0.0;
    int count = 0;
    cout << "Enter at most 10 donations (type non-digits to terminate):\n";
    int i = 0;
    while (i < MAX && cin >> donations[i])
        total += donations[i++];
    ave = total / i;
    cout << "Average: " << ave << endl;
    for (int j = 0; j < i; ++j)
        if (donations[j] > ave)
            ++count;
    cout << "There are " << count << " numbers greater than ave." << endl;
    return 0;
}

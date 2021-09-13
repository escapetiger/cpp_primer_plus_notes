#include <iostream>
#include <string>
using namespace std;

int main()
{
    int lineNum = 0;
    cout << "Enter number of rows: ";
    cin >> lineNum;
    for (int i = 1; i <= lineNum; ++i)
    {
        string lhs(lineNum - i, '.'), rhs(i, '*');
        cout << lhs + rhs << endl;
    }
    return 0;
}

/******************************************************************************
* File:             check_it.cpp
*
* Author:           Joey Tsai  
* Created:          09/07/21 
* Description:      checking for valid input
*****************************************************************************/

#include <iostream>
int main(void)
{
    using namespace std;
    cout << "Enter numbers: ";

    int sum = 0;
    int input;
    while (cin >> input) {
        sum += input;
    }

    cout << "Last value entered = " << input << endl;
    cout << "Sum = " << sum << endl;
    return 0;
}

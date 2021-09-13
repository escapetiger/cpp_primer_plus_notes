// arrfun1.cpp -- functions with an array argument
#include <iostream>
using namespace std;
const int ArSize = 8;
int sum_arr(int arr[], int n); // prototype

int main()
{
    int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};
    int sum = sum_arr(cookies, ArSize);
    cout << "Total cookies eaten: " << sum << "\n";
    return 0;
}

// return the sum of an integer array
int sum_arr(int arr[], int n)
{
    int total = 0;
    for (int i = 0; i < n; ++i)
        total = total + arr[i];
    return total;
}

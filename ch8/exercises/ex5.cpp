// ex5.cpp -- template function max5
#include <iostream>
using namespace std;
const int ArSize = 5;
template <typename T>
T max5(T arr[], int n);

int main()
{
    cout.setf(ios_base::fixed, ios_base::floatfield);
    int a[ArSize] = {1, 2, 3, 4, 5};
    double b[ArSize] = {1.0, 2.0, 3.0, 4.0, 5.0};
    cout << "The max number of int array is: " << max5(a, ArSize) << endl;
    cout << "The max number of double array is: " << max5(b, ArSize) << endl;

    return 0;
}

template <typename T>
T max5(T arr[], int n)
{
    T max_elt = arr[0];
    for (int i = 1; i < n; ++i)
        if (arr[i] > max_elt)
            max_elt = arr[i];
    return max_elt;
}

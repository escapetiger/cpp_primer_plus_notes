// maxn.cpp -- template function maxn
#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
T maxn(T arr[], int n);

template <> char * maxn(char *arr[], int n); // specialization
int main()
{
    int iarr[6] = {1, 2, 3, 4, 5, 6};
    double darr[4] = {2, 5, 12, 1};
    char *carr[] =
    {
        (char *)"caiyi",
        (char *)"caijianshe",
        (char *)"xiaxiaoqiu",
        (char *)"majinhua",
        (char *)"yangjingyu"
    };

    cout << "The max number of iarr is: " << maxn(iarr, 6) << endl;
    cout << "The max number of darr is: " << maxn(darr, 4) << endl;
    cout << "The longest string of carr is: " << maxn(carr, 5) << endl;

    return 0;
}

template <typename T>
T maxn(T arr[], int n)
{
    if (!arr[0])
        cout << "You passed an empty array!" << endl;
    T max_elt;
    for (int i = 0; i < n; ++i)
        if (arr[i] > max_elt)
            max_elt = arr[i];
    return max_elt;
}

template <> char * maxn(char *arr[], int n)
{
    if (!arr[0])
        cout << "You passed an empty array!" << endl;
    char *max_str;
    int max_len = (int) strlen(arr[0]);
    for (int i = 1; i < n; ++i)
    {
        if (strlen(arr[i]) > max_len)
        {
            max_len = (int) strlen(arr[i]);
            max_str = arr[i];
        }

    }
    return max_str;
}

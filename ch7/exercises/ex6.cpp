// ex6.cpp -- array operation
#include <iostream>
using namespace std;

const unsigned int ARR_SIZE_MAX = 5;
// prototypes
unsigned int FillArray(double arr[], unsigned int arrsize);
void ShowArray(const double arr[], unsigned int arrsize);
void ReverseArray(double arr[], unsigned int arrsize);


int main()
{
    double *arr1 = new double[ARR_SIZE_MAX];
    unsigned int arrsize = FillArray(arr1, ARR_SIZE_MAX);
    ShowArray(arr1, arrsize);

    cout << "After apply reverse algorithm:\n";
    ReverseArray(arr1, arrsize);
    ShowArray(arr1, arrsize);

    return 0;
}

unsigned int FillArray(double arr[], unsigned int arrsize)
{
    cout << "Enter an array of double:\n";
    int ct = 0;
    while (ct < arrsize && cin >> arr[ct]) ++ct;
    return ct;
}

void ShowArray(const double arr[], unsigned int arrsize)
{
    cout << "The array of double:\n";
    for (int i = 0; i < arrsize; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void ReverseArray(double arr[], unsigned int arrsize)
{
    double temp = 0.0;
    for (int i = 0, j = arrsize - 1; i < j; ++i, --j)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

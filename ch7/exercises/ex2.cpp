// ex2.cpp -- golf grade
#include <iostream>
using namespace std;
// contants
const int MaxArSize = 10;
// prototypes
int Fill(double grades[], int MaxArSize);
void Show(const double grades[], int ArSize);
double Average(const double grades[], int ArSize);

int main()
{
    double *grades = new double[MaxArSize];

    cout << "Enter your golf grades (q to finish):\n";
    int ArSize = Fill(grades, MaxArSize);
    Show(grades, ArSize);
    cout << "Your average grade is: " << Average(grades, ArSize) << endl;

    return 0;
}

int Fill(double grades[], int MaxArSize)
{
    int ct = 0;
    while (ct < MaxArSize && cin >> grades[ct]) ++ct;
    return ct;
}

void Show(const double grades[], int ArSize)
{
    cout << "You grades are shown below:\n";
    for (int i = 0; i < ArSize; ++i) {
        cout << grades[i] << " " << endl;
    }
}

double Average(const double grades[], int ArSize)
{
    double total = 0.0;
    for (int i = 0; i < ArSize; ++i) {
        total += grades[i];
    }
    return total / ArSize;
}

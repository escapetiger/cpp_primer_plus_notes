// usetime1.cpp -- using the first draft of the Time class
// compile usetime0.cpp and mytime0.cpp together
#include <iostream>
#include "mytime1.h"

int main()
{
    using std::cout;
    using std::endl;
    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;

    cout << "planning time = ";
    planning.Show();
    cout << endl;

    cout << "coding time = ";
    coding.Show();
    cout << endl;

    cout << "fixing time = ";
    fixing.Show();
    cout << endl;

    // operator notation
    total = coding + fixing;
    cout << "coding + fixing = ";
    total.Show();
    cout << endl;

    // function notation
    Time morefixing(3, 28);
    cout << "morefixing time = ";
    morefixing.Show();
    cout << endl;
    total = morefixing.operator+(total);
    cout << "morefixing.operator+(total) = ";
    total.Show();
    cout << endl;


    return 0;
}

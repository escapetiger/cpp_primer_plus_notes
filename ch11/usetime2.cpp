// usetime2.cpp -- using the first draft of the Time class
// compile usetime0.cpp and mytime0.cpp together
#include <iostream>
#include "mytime2.h"

int main()
{
    using std::cout;
    using std::endl;
    Time weeding(4, 35);
    Time waxing(2, 40);
    Time total;
    Time diff;
    Time adjusted;

    cout << "weeding time = ";
    weeding.Show();
    cout << endl;

    cout << "waxing time = ";
    waxing.Show();
    cout << endl;

    cout << "total work time = ";
    total = weeding + waxing;
    total.Show();
    cout << endl;

    cout << "weeding time - waxing time = ";
    diff = weeding - waxing;
    diff.Show();
    cout << endl;

    cout << "adjusted work time = ";
    adjusted = total * 1.5;
    adjusted.Show();
    cout << endl;

    return 0;
}

// ex4.cpp
#include <iostream>
#include "sales.h"

int main()
{
    using namespace std;
    SALES::Sales s1, s2;
    double ar1[3] = {1.0, 2.0, 3.0};
    SALES::setSales(s1, ar1, 3);
    SALES::setSales(s2);
    SALES::showSales(s1);
    SALES::showSales(s2);
    
    return 0;
}

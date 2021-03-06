#include <iostream>
#include <iomanip>
#include "sales.h"

namespace SALES
{
    void setSales(Sales & s, const double ar[], int n)
    {
        int ssize = (n < QUATERS) ? n : QUATERS;
        double total = 0.0;
        for (int i = 0; i < ssize; ++i)
        {
            s.sales[i] = ar[i];
            total += ar[i];
        }
        s.average = total / ssize;
        s.max = s.min = ar[0];
        for (int i = 0; i < ssize; ++i) {
            s.max = (s.max < ar[i]) ? ar[i] : s.max;
            s.min = (s.min > ar[i]) ? ar[i] : s.min;
        }
    }

    void setSales(Sales & s)
    {
        double total = 0.0;
        std::cout << "Please enter season sales below." << std::endl;
        for (int i = 0; i < QUATERS; ++i)
        {
            std::cout << "Season #" << i + 1 << ": ";
            std::cin >> s.sales[i];
            total += s.sales[i];
        }
        s.average = total / QUATERS;
        s.max = s.min = s.sales[0];
        for (int i = 0; i < QUATERS; ++i) {
            s.max = (s.max < s.sales[i]) ? s.sales[i] : s.max;
            s.min = (s.min > s.sales[i]) ? s.sales[i] : s.min;
        }
    }

    void showSales(const Sales & s)
    {
        std::cout << std::setw(10) << " Season ";
        std::cout << std::setw(8) << " Sales ";
        std::cout << std::endl;
        for (int i = 0; i < QUATERS; ++i)
        {
            std::cout << std::setw(10) << " " << i + 1 << " ";
            std::cout << std::setw(8) << " " << s.sales[i] << " ";
            std::cout << std::endl;
        }
        std::cout << "Average: " << s.average << ", "
                  << "Max: " << s.max << ", "
                  << "Min: " << s.min << std::endl;
    }

}

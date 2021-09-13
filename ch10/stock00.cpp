// stock00.cpp -- implementing the Stock class
// version 00
#include <ios>
#include <iostream>
#include "stock00.h"

void Stock::acquire(const std::string & co, long n, double pr)
{
    company = co;
    if (n < 0)
    {
        std::cout << "Number of shares can't be negative; "
                  << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

void Stock::buy(long num, double price)
{
    if (num < 0)
        std::cout << "Number of shares purchased can't be negative. "
                  << "Transaction is aborted.\n";
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    if (num < 0)
        std::cout << "Number of shares sold can't be negative. "
                  << "Transaction is aborted.\n";
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::show()
{
    std::streamsize prec = std::cout.precision(2); // save preceding value for precision
    std::ios_base::fmtflags orig = std::cout.setf(std::ios_base::fixed); // store original flags
    std::cout << "Company: " << company
              << " Shares: " << shares << '\n'
              << " Shares Price: $" << share_val
              << " Total Worth: $" << total_val << '\n';
    std::cout.precision(prec); // reset to old value
    std::cout.setf(orig, std::ios_base::floatfield); // reset to stored values
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

inline void Stock::set_tot()
{
    total_val = shares * share_val;
}

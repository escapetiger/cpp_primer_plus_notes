#include <iostream>
#include <cstring>
#include "stock30.h"

// constructors (verbose versions)
Stock::Stock() // default constructor
{
    company = nullptr;
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const char * co, long n, double pr)
{
    company = new char[std::strlen(co) + 1];
    std::strcpy(company, co);
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

// class destructor
Stock::~Stock() // verbose class destructor
{
    delete [] company;
}

// other method
void Stock::acquire(const char * co, long n, double pr)
{
    company = new char[std::strlen(co) + 1];
    std::strcpy(company, co);
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

std::ostream & operator<<(std::ostream & os, const Stock & obj)
{
    std::streamsize prec = os.precision(2); // save preceding value for precision
    std::ios_base::fmtflags orig = os.setf(std::ios_base::fixed); // store original flags
    os << "Company: " << obj.company
              << " Shares: " << obj.shares << '\n'
              << " Shares Price: $" << obj.share_val
              << " Total Worth: $" << obj.total_val << '\n';
    os.precision(prec); // reset to old value
    os.setf(orig, std::ios_base::floatfield); // reset to stored values
    return os;
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

const Stock & Stock::topval(const Stock & s) const
{
	return (s.total_val > total_val) ? s : *this;
}

inline void Stock::set_tot()
{
    total_val = shares * share_val;
}

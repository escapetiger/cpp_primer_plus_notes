// stock30.h -- augmented version
// version 30
#ifndef STOCK30_H_
#define STOCK30_H_


#include <iostream>
class Stock // class declaration
{
private:
    char * company;
    long shares;
    double share_val;
    double total_val;
    void set_tot();
public:
    Stock(); // default constructor
    Stock(const char * co, long n = 3, double pr = 0.0);
    ~Stock(); // default destructor
    void acquire(const char * co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    const Stock & topval(const Stock & s) const;
    friend std::ostream & operator<<(std::ostream & os, const Stock & obj);
}; // note semicolon at the end

#endif

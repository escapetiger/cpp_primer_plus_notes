// stock10.h -- Stock class declaration with constructors, destructor added
// version 10
#ifndef STOCK10_H_
#define STOCK10_H_

#include <string>

class Stock // class declaration
{
private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot();
public:
    Stock(); // default constructor
    Stock(const std::string & co, long n = 3, double pr = 0.0);
    ~Stock(); // default destructor
    void acquire(const std::string & co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
}; // note semicolon at the end

#endif

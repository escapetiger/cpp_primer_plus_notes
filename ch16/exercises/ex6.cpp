/******************************************************************************
* File:             ex6.cpp
*
* Author:           Joey Tsai
* Created:          09/07/21
* Description:      using STL queue
*****************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
const int MIN_PER_HR = 60;

// This queue will contain Customer items
class Customer
{
private:
    long arrive;     // arrival time for customer
    int processtime; // processing time for customer
public:
    Customer(){ arrive = processtime = 0; }
    virtual ~Customer ();
    void set(long when);
    long when() const {return arrive;}
    int ptime() const {return processtime;}
};

bool newcustomer(double x); // is there a new customer?


int main(void)
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    using std::queue;
    typedef Customer Item;
    // setting things up
    std::srand(std::time(0));            // random initializing of rand()

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    queue<Item> line;                      // line queu holds up to qs people

    cout << "Enter the number of simulation hours: ";
    int hours;                           // hours of simulation
    cin >> hours;
    // simulation will run 1 cycle per minute
    long cyclelimit = MIN_PER_HR * hours;

    cout << "Enter the average number of customers per hour: ";
    double perhour;                      // average # of arrival per hour
    cin >> perhour;
    double min_per_cust;                 // average time between arrivals
    min_per_cust = MIN_PER_HR / perhour;

    Item temp;                           // new customer data
    long turnaways = 0;                  // turned away by full queue
    long customers = 0;                  // joined the queue
    long served = 0;                     // served during the simulation
    long sum_line = 0;                   // cumulative line length
    int wait_time = 0;                   // time until autoteller is free
    long line_wait = 0;                  // cumulative time in line

    // running the simulation
    for (int cycle = 0; cycle < cyclelimit; ++cycle)
    {
        if (newcustomer(min_per_cust)) // have newcomer
        {
            if (line.size() == qs)
                turnaways++;
            else
            {
                customers++;
                temp.set(cycle);    // cycle = time of arrival
                line.push(temp); // add newcomer to line
            }
        }
        if (wait_time <= 0 && line.size() != 0)
        {
            temp = line.front();
            line.pop();
            wait_time = temp.ptime();
            line_wait += cycle - temp.when() ;
            served++;
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += line.size();

    }

    // reporting results
    if (customers > 0)
    {
        cout << "customers accpeted: " << customers << endl;
        cout << "  customers served: " << served << endl;
        cout << "         turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line / cyclelimit << endl;
        cout << " average wait time: "
             << (double) line_wait / served << " minutes\n";
    }
    else
        cout << "No customers!\n";
    cout << "Done!\n";
    return 0;
}

// x = average time, in minutes, between customers
// return value is true if customer shows up this minute
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}

void Customer::set(long when)
{
    processtime = std::rand() % 3 + 1;
    arrive = when;
}

Customer::~Customer()
{
}

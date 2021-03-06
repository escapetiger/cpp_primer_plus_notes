/******************************************************************************
* File:             ex5.cpp
*
* Author:           Joey Tsai
* Created:          08/30/21
* Description:      how many customer shall we have so that the average waiting time is no more than 1 minite.
*****************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"
const int MIN_PER_HR = 60;

double test(int qs, long climit, double mpc);
bool newcustomer(double x); // is there a new customer?

int main(void)
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    // setting things up
    std::srand(std::time(0));            // random initializing of rand()

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;

    cout << "Enter the number of simulation hours: ";
    int hours;                           // hours of simulation
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours;
    // simulation will run 1 cycle per minute

    cout << "Enter the average number of customers per hour: ";
    double perhour;                             // average # of arrival per hour
    double ave;
    while (cin >> perhour)
    {
        double min_per_cust = MIN_PER_HR / perhour; // average time between arrivals
        ave = test(qs, cyclelimit, min_per_cust);
        cout << "Enter the average number of customers per hour: ";
    }
    return 0;
}

// x = average time, in minutes, between customers
// return value is true if customer shows up this minute
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}

double test(int qs, long climit, double mpc)
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    Queue line(qs);                      // line queu holds up to qs people

    Item temp;                           // new customer data
    long turnaways = 0;                  // turned away by full queue
    long customers = 0;                  // joined the queue
    long served = 0;                     // served during the simulation
    long sum_line = 0;                   // cumulative line length
    int wait_time = 0;                   // time until autoteller is free
    long line_wait = 0;                  // cumulative time in line

    // running the simulation
    for (int cycle = 0; cycle < climit; ++cycle)
    {
        if (newcustomer(mpc)) // have newcomer
        {
            if (line.isfull())
                turnaways++;
            else
            {
                customers++;
                temp.set(cycle);    // cycle = time of arrival
                line.enqueue(temp); // add newcomer to line
            }
        }
        if (wait_time <= 0 && !line.isempty())
        {
            line.dequeue(temp);
            wait_time = temp.ptime();
            line_wait += cycle - temp.when() ;
            served++;
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += line.queuecount();

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
        cout << (double) sum_line / climit << endl;
        cout << " average wait time: "
             << (double) line_wait / served << " minutes\n";
    }
    else
        cout << "No customers!\n";
    cout << "Done!\n";

    return (double) line_wait / served;
}

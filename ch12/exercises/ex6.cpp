/******************************************************************************
* File:             ex6.cpp
*
* Author:           Joey Tsai
* Created:          08/30/21
* Description:      Two ATM
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

    cout << "Enter the average number of customers per hour (q to quit): ";
    double perhour;                             // average # of arrival per hour
    double ave;
    while (cin >> perhour)
    {
        double min_per_cust = MIN_PER_HR / perhour; // average time between arrivals
        ave = test(qs, cyclelimit, min_per_cust);
        cout << "Enter the average number of customers per hour (q to quit): ";
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
    Queue line1(qs);                      // line1 queue holds up to qs people
    Queue line2(qs);                      // line2 queue holds up to qs people

    Item temp;                           // new customer data
    long turnaways = 0;                  // turned away by full queue
    long customers = 0;                  // joined the queue
    long served = 0;                     // served during the simulation
    long sum_line1 = 0;                   // cumulative line1 length
    long sum_line2 = 0;                   // cumulative line2 length
    int wait_time1 = 0;                   // time until autoteller is free
    int wait_time2 = 0;                   // time until autoteller is free
    long line1_wait = 0;                  // cumulative time in line1
    long line2_wait = 0;                  // cumulative time in line2

    // running the simulation
    for (int cycle = 0; cycle < climit; ++cycle)
    {
        if (newcustomer(mpc)) // have newcomer
        {
            if (line1.isfull() && line2.isfull())
                turnaways++;
            else if (sum_line1 <= sum_line2)
            {
                customers++;
                temp.set(cycle);
                line1.enqueue(temp);
            }
            else if (sum_line1 > sum_line2)
            {
                customers++;
                temp.set(cycle);    // cycle = time of arrival
                line2.enqueue(temp); // add newcomer to line
            }
        }
        if (wait_time1 <= 0 && !line1.isempty())
        {
            line1.dequeue(temp);
            wait_time1 = temp.ptime();
            line1_wait += cycle - temp.when() ;
            served++;
        }
        if (wait_time1 > 0)
            wait_time1--;

        if (wait_time2 <= 0 && !line2.isempty())
        {
            line2.dequeue(temp);
            wait_time2 = temp.ptime();
            line2_wait += cycle - temp.when();
            served++;
        }
        if (wait_time2 > 0)
            wait_time2--;

        sum_line1 += line1.queuecount();
        sum_line2 += line2.queuecount();
    }

    // reporting results
    if (customers > 0)
    {
        cout << "customers accpeted: " << customers << endl;
        cout << "  customers served: " << served << endl;
        cout << "         turnaways: " << turnaways << endl;
        cout << "average line1 size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line1 / climit << endl;
        cout << "average line2 size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line2 / climit << endl;
        cout << " average wait time: "
             << (double) (line1_wait + line2_wait)/ served << " minutes\n";
    }
    else
        cout << "No customers!\n";
    cout << "Done!\n";

    return (double) (line1_wait + line2_wait) / served;
}

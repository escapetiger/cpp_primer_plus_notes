// lotto.cpp -- probability of winning
#include <iostream>
// Note: someimplementations require double insead of long double
long double probability(unsigned numbers, unsigned picks);
using namespace std;

int main()
{
    double total, choices;
    cout << "Enter the total number of choices on the game card and\n"
        "the number of picks allowed:\n";
    while ((cin >> total >> choices) && choices <= total) {
       cout << "You have one chance in " ;
       cout << probability(total, choices); // compute the odds
       cout << " of winning.\n";
       cout << "Next two numbers (q to quit): ";
    }
    
    return 0;
}

// the following function calculates the probability of picking picks
// numbers correctly from numbers choices
long double probability(unsigned numbers, unsigned picks)
{
    long double result = 1.0;
    long double n;
    unsigned int p;
    for(n = numbers, p = picks; p > 0; n--, p--)
        result  = result * n / p;
    return result;
}

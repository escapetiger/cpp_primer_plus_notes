// ex4.cpp -- extension of lotto.cpp
#include <iostream>
// Note: someimplementations require double insead of long double
long double Prob(unsigned numbers, unsigned picks);
using namespace std;

int main()
{
    double field_number, field_choices;
    double special_number, special_choices;
    cout << "Enter the total number of field number and special number on the game card and\n"
        "the number of field number and special number picks allowed:\n";
    while ( cin >> field_number >> field_choices >> special_number >> special_choices 
            && field_choices<= field_number 
            && special_choices < special_number) {
       cout << "You have one chance in " ;
       cout << Prob(field_number, field_choices) * Prob(special_number, special_choices); // compute the odds
       cout << " of winning.\n";
       cout << "Next four numbers (q to quit): ";
    }
    
    return 0;
}

// the following function calculates the probability of picking picks
// numbers correctly from numbers choices
long double Prob(unsigned numbers, unsigned picks)
{
    long double result = 1.0;
    long double n;
    unsigned int p;
    for(n = numbers, p = picks; p > 0; n--, p--)
        result  = result * n / p;
    return result;
}

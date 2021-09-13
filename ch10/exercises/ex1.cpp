// ex1.cpp -- use Account class
// compiled with account.cpp
#include <iostream>
#include <string>
#include "account.h"

int main()
{
    using namespace std;
    Account ac("Cai Yi", "123456789", 1e+8);
    ac.save(1e+8);
    ac.withdraw(1);

    return 0;
}

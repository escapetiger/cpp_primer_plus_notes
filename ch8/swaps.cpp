// swaps.cpp -- swapping with references and with pointers
#include <iostream>
using namespace std;
void swapr(int &a, int &b); // a, b are aliases for ints
void swapp(int *p, int *q); // p, q are addresses of ints
void swapv(int a, int b); // a, b are new variables

int main()
{
    int wallet1 = 300;
    int wallet2 = 350;
    cout << "wallet1 = $" << wallet1;
    cout << ", wallet2 = $" << wallet2 << endl;

    cout << "Using references to swap contents:\n";
    swapr(wallet1, wallet2); // pass varaibles
    cout << "wallet1 = $" << wallet1;
    cout << ", wallet2 = $" << wallet2 << endl;

    cout << "Using pointers to swap contents:\n";
    swapp(&wallet1, &wallet2); // pass addresses of variables
    cout << "wallet1 = $" << wallet1;
    cout << ", wallet2 = $" << wallet2 << endl;

    cout << "Using references to swap contents:\n";
    swapv(wallet1, wallet2); // pass values of variables
    cout << "wallet1 = $" << wallet1;
    cout << ", wallet2 = $" << wallet2 << endl;
    
    return 0;
}

void swapr(int &a, int &b) // use references
{
    int temp;
    temp = a; a = b; b = temp; // use a, b for values of variables
}

void swapp(int *p, int *q) // use pointers
{
    int temp;
    temp = *p; *q = *p; *p = temp; // use *p, *q for value of variables

}

void swapv(int a, int b)
{
    int temp;
    temp = a; a = b; b = temp;
}

// pointer.cpp -- our first pointer variable
#include <iostream>
int main(void)
{
    using namespace std;
    int updates = 6;      // declare a variable
    int *p_updates;       // declare pointer to an int
    p_updates = &updates; // assign address of int to pointer

    // express values two ways
    std::cout << "Values: updates = " << updates
              << ", *p_updates = " << *p_updates << std::endl;

    // express address two ways
    std::cout << "Addresses: &updates = " << &updates
              << ", &p_updates = " << &p_updates << std::endl;

    // use pointer to change value
    *p_updates = *p_updates + 1;
    std::cout << "Now updates = " << updates << std::endl;

    return 0;
}

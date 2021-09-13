// bigstep.cpp -- count as diected
#include <iostream>
int main(void)
{
    int by;
    std::cout << "Enter an interger: ";
    std::cin >> by;
    std::cout << "COunting by " << by << "s:" << std::endl;
    for (int i = 0; i < 100; i = i + by) {
        std::cout << i << std::endl;
    }
    return 0;
}

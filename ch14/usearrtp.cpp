/******************************************************************************
* File:             usearrtp.cpp
*
* Author:           Joey Tsai  
* Created:          09/04/21 
* Description:      use ArrayTP class template
*****************************************************************************/

#include <iostream>
#include "arraytp.h"
const int SIZE = 5;

int main(void)
{
    ArrayTP<double, SIZE> arr(0.0);
    const ArrayTP<double, SIZE> carr(0.0);
    std::cout << "arr: ";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "carr: ";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << carr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

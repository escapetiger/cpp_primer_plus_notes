#include <iostream>
int main(void)
{
    double lat;
    int deg, min, sec;
    std::cout << "Enter a latitude in degrees, minutes, and seconds:" << std::endl;
    std::cout << "First, enter the degrees: ";
    std::cin >> deg;
    std::cout << "Second, enter the minutes of arc: "; 
    std::cin >> min;
    std::cout << "Third, enter the seconds of arc: ";
    std::cin >> sec;

    lat = deg + min / 60.0 + sec / 3600.0;
    std::cout << deg << " degrees, "
              << min << " minutes, "
              << sec << " seconds = "
              << lat << " degrees." << std::endl;

    return 0;
}

#include <cstdlib>
#include <iostream>
#include <array>
int main(void)
{
    std::array<double, 3> grades;
    std::cout << "Enter your 40m grades(three times):" << std::endl;
    std::cin >> grades[0];
    std::cin >> grades[1];
    std::cin >> grades[2];

    double ave_grade;
    ave_grade = (grades[0] + grades[1] + grades[2]) / 3;
    std::cout << "First grade: " << grades[0] << std::endl;
    std::cout << "Second grade: " << grades[1] << std::endl;
    std::cout << "Third grade: " << grades[2] << std::endl;
    std::cout << "Your average grade: " << ave_grade << std::endl;
    return 0;
}

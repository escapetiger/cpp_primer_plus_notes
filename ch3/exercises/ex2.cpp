#include <iostream>
int main(void)
{
    double height, weight, BMI;
    int foot, inch, pound;

    std::cout << "Enter your height:(xx foot xx inch)" << std::endl;
    std::cin >> foot >> inch;

    std::cout << "Enter your weight:(xx pounds)" << std::endl;
    std::cin >> pound;

    height = (12 * foot + inch) * 0.0254;
    weight = pound / 2.2;
    BMI = weight / (height * height);

    std::cout << "Your height is " << height << " m." << std::endl;
    std::cout << "Your weight is " << weight << " kg." << std::endl;
    std::cout << "Your BMI is: " << BMI << std::endl;
    return 0;
}

#include <iostream>
#include <string>
struct Student
{
    std::string firstName;
    std::string lastName;
    char grade;
    int age;
};
int main()
{
    Student stu;
    std::cout << "What is your first name? ";
    getline(std::cin, stu.firstName);
    std::cout << "What is your last name? ";
    getline(std::cin, stu.lastName);
    std::cout << "What letter grade do you deserve? ";
    std::cin >> stu.grade;
    stu.grade = stu.grade + 1;
    std::cout << "What is your age? ";
    std::cin >> stu.age;
    std::cout << "Name: "<<stu.lastName << ", " << stu.firstName << std::endl;
    std::cout << "Grade: " << stu.grade << std::endl;
    std::cout << "Age: " << stu.age << std::endl;
    return 0;
}

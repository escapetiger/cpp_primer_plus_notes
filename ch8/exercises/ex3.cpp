// ex3.cpp -- toupper for string
#include <cctype>
#include <cwctype>
#include <iostream>
#include <string>

void toupper(std::string &str);

int main()
{
    std::string str;
    std::cout << "Enter a string (q to quit): ";
    while (getline(std::cin, str) && str != "q")
    {
        toupper(str);
        std::cout << str << "\n";
        std::cout << "Next string (q to quit): ";
    }

    return 0;
}

void toupper(std::string &str)
{
    for (int i = 0; i < str.size(); ++i)
        str[i] = std::toupper(str[i]);
}

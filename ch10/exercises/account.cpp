// account.cpp -- member functions for Account class
#include <iostream>
#include "account.h"
Account::Account()
{
    std::cout << "Default constructor is called.\n";
    m_name = "FullName";
    m_acc = "000000000000";
    m_dep = 0.0;
    show(*this);
}

Account::Account(const std::string & name, const std::string & ac, double dp)
{
    std::cout << "Constructor is called.\n";
    m_name = name;
    m_acc = ac;
    m_dep = dp;
    show(*this);
}
void Account::show(const Account & ac) const
{
    std::cout << "Name: " << ac.m_name << "\n";
    std::cout << "Account: " << ac.m_acc << "\n";
    std::cout << "Deposit: " << ac.m_dep << "\n";
}

void Account::save(double money)
{
    m_dep += money;
    std::cout << "You have saved $" << money << " successfully.\n";
    std::cout << "Your current deposit is $" << m_dep << ".\n";
}

void Account::withdraw(double money)
{
    m_dep -= money;
    std::cout << "You have withdrawed $" << money << " successfully.\n";
    std::cout << "Your current deposit is $" << m_dep << ".\n";
}

Account::~Account()
{
    std::cout << "Deconstructor is called.\n";
}

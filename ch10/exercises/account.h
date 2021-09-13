// account.h -- bank account class
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account
{
private:
    std::string m_name;
    std::string m_acc;
    double m_dep;

public:
    Account();
    Account(const std::string & name, const std::string & ac, double dp);
    virtual ~Account();
    void save(double money);
    void withdraw(double money);
    void show(const Account & ac) const;
};

#endif /* ACCOUNT_H */

// person.h -- declarations of Person class
#ifndef PERSON_H
#define PERSON_H

#include <string>
class Person
{
private:
    static const int LIMIT = 25;
    std::string lname; // Person's last name
    std::string fname; // Person's first name

public:
    Person(); // #1
    Person(const std::string & ln, const std::string & fn = "Heyyou"); // #2
    virtual ~Person();
    void show() const;       // fristname lastname format
    void FormalShow() const; // last name, firstname format
};

#endif /* PERSON_H */

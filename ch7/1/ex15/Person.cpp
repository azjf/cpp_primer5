#include "Person.h"

Person::Person(std::istream &is)
{
    read(is, *this);
}

std::istream &read(std::istream &is, Person &person)
{
    is >> person.name >> person.address;
    return is;
}

std::ostream &print(std::ostream &os, const Person &person)
{
    os << person.name << ", " << person.address;
    return os;
}

#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>

struct Person
{
    Person() = default;
    Person(std::string name) : name(name) { }
    Person(std::string name, std::string address) :
        name(name), address(address) { }
    Person(std::istream &is);

    std::string get_name() const { return name; }
    std::string get_address() const { return address; }

    std::string name;
    std::string address;
};

std::istream &read(std::istream &is, Person &person);
std::ostream &print(std::ostream &os, const Person &person);
#endif

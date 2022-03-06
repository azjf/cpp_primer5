#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

class Employee
{
public:
    Employee() : id(std::to_string(uuid++)) {}
    Employee(const std::string &n) : name(n), id(std::to_string(uuid++)) {}
    Employee(const Employee &e) : name(e.name), id(std::to_string(uuid++)) {}
    Employee &operator=(const Employee &rhs);

private:
    static unsigned uuid;
    std::string name;
    std::string id;
};

#endif

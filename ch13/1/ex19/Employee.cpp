#include "Employee.h"

unsigned Employee::uuid = 0;

Employee &Employee::operator=(const Employee &rhs)
{
    name = rhs.name;
    id = std::to_string(uuid++);
    return *this;
}

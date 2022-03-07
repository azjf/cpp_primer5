#include "HasPtr.h"

HasPtr &HasPtr::operator=(const HasPtr &rhs)
{
    ps = new std::string(*rhs.ps);
    i = rhs.i;
    return *this;
}

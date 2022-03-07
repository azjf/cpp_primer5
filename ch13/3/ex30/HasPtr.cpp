#include "HasPtr.h"

HasPtr &HasPtr::operator=(const HasPtr &rhs)
{
    auto newp = new std::string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;
    return *this;
}

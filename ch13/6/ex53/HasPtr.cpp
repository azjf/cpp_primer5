#include "HasPtr.h"

HasPtr &HasPtr::operator=(const HasPtr &rhs)
{
    auto newp = new std::string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;
    return *this;
}

HasPtr &HasPtr::operator=(HasPtr &&rhs) noexcept
{
    if (this != &rhs) {
        ps = rhs.ps;
        i = rhs.i;
        rhs.ps = nullptr;
        rhs.i = 0;
    }
    return *this;
}

//HasPtr &HasPtr::operator=(HasPtr rhs)
//{
//    swap(*this, rhs);
//    return *this;
//}

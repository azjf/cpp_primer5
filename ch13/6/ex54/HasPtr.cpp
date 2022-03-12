#include <iostream>

#include "HasPtr.h"

HasPtr &HasPtr::operator=(const HasPtr &rhs)
{
    std::cout << "operator=(const Hasptr &)" << std::endl;
    auto newp = new std::string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;
    return *this;
}

HasPtr &HasPtr::operator=(HasPtr &&rhs) noexcept
{
    std::cout << "operator=(Hasptr &&)" << std::endl;
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
//    std::cout << "operator=(Hasptr)" << std::endl;
//    swap(*this, rhs);
//    return *this;
//}

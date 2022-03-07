#ifndef HASPTR_H
#define HASPTR_H
#include <string>
#include <iostream>

class HasPtr
{
    friend void swap(HasPtr &, HasPtr &);

public:
    HasPtr(const std::string &s = std::string()) :
        ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &p) : ps(new std::string(*p.ps)), i(p.i) {}
    ~HasPtr() { delete ps; }

    HasPtr &operator=(const HasPtr &p);

private:
    std::string *ps;
    int i;
};

inline
void swap(HasPtr &lhs, HasPtr &rhs)
{
    std::cout << "swap(HasPtr &, HasPtr &)" << std::endl;
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}
#endif

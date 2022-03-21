#include <iostream>
#include <memory>
#include <vector>

class Base {};

class D : public Base
{
    D(const D &d) : Base(d) {}
    D(D &&d) : Base(std::move(d)) {}
    D &operator=(const D &&);
    ~D() {}
};

D &D::operator=(const D &&rhs)
{
    Base::operator=(rhs);
    return *this;
}

int main()
{
    return 0;
}

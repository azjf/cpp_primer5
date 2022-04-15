#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include <numeric>

#include "Sales_data.h"

class Base
{
    friend bool operator==(const Base &, const Base &);

public:
    virtual void dummy() const { std::cout << "Base::dummy()" << std::endl; }
    virtual bool equal(const Base &) const;
};

class Derived : public Base
{
public:
    void print() const { std::cout << "Derived:print()" << std::endl; }
    bool equal(const Base &) const;
};

void f(const Base &b)
{
    try {
        const Derived &d = dynamic_cast<const Derived &>(b);
        d.print();
        d.dummy();
    } catch (std::bad_cast &) {
        b.dummy();
    }

}

bool operator==(const Base &lhs, const Base &rhs)
{
    return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
}

bool Derived::equal(const Base &rhs) const
{
    auto r = dynamic_cast<const Derived &>(rhs);
    return true;
}

bool Base::equal(const Base &rhs) const
{
    return true;
}

int main()
{
    int arr[10];
    Derived d;
    Base *p = &d;
    std::cout << typeid(42).name() << ", "
        << typeid(arr).name() << ", "
        << typeid(Sales_data).name() << ", "
        << typeid(std::string).name() << ", "
        << typeid(p).name() << ", "
        << typeid(*p).name() << std::endl;
    return 0;
}

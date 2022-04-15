#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include <numeric>

class A
{
public:
    virtual ~A() = default;

    virtual void dummy()
    {
        std::cout << "A::dummy()" << std::endl;
    }
};

class B : public A {};

class C : public B
{
public:
    void print()
    {
        std::cout << "C::print()" << std::endl;
    }
};

class D : public B, public A {};

int main()
{
    {
    A *pa = new C;
    if (C *pc = dynamic_cast<C *>(pa)) {
        pc->print();
    } else {
        pa->dummy();
    }
    }

    A *pa = new B;
    if (C *pc = dynamic_cast<C *>(pa)) {
        pc->print();
    } else {
        pa->dummy();
    }
    return 0;
}

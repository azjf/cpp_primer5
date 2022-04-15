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

    virtual void dummy() {}
};

class B : public A {};
class C : public B {};
class D : public B, public A {};

int main()
{
    {
    A *pa = new C;
    if (B *pb = dynamic_cast<B *>(pa)) {
        std::cout << "(a): succeeded" << std::endl;
    }
    }

    {
    B *pb = new B;
    if (C *pc = dynamic_cast<C *>(pb)) {
        std::cout << "(b): succeeded" << std::endl;
    }
    }

    //A *pa = new D;
    //B *pb = dynamic_cast<B *>(pa);
    return 0;
}

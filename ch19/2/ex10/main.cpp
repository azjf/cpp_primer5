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
};

class B : public A {};
class C : public B {};

int main()
{
    {
    A *pa = new C;
    std::cout << typeid(pa).name() << std::endl;

    C cobj;
    A &ra = cobj;
    std::cout << typeid(&ra).name() << std::endl;
    }

    B *px = new B;
    A &ra = *px;
    std::cout << typeid(ra).name() << std::endl;
    return 0;
}

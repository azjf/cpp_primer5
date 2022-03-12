#include <iostream>
#include "StrVec.h"
#include "HasPtr.h"

struct X
{
    int i;
    std::string s;
};

struct hasX
{
    X mem;
};

struct Y
{
    Y() = default;
    Y(Y &&) = delete;
};

struct hasY
{
    hasY() = default;
    hasY(hasY &&) = default;
    Y mem;
};

StrVec getVec(std::istream &) { return StrVec(); }

class Foo
{
public:
    Foo() = default;
    Foo(const Foo &) {}
};


int main()
{
    {
    int i = 42;
    int &r = i;
    //int &&rr = i;
    //int &r2 = i * 42;
    const int &r3 = i * 42;
    int &&rr2 = i * 42;
    }

    {
    int &&rr1 = 42;
    //int &&rr2 = rr1;
    }

    {
    X x, x2 = std::move(x);
    hasX hx, hx2 = std::move(hx);
    }

    {
    //hasY hy, hy2 = std::move(hy);
    }

    {
    StrVec v1, v2;
    v1 = v2;
    v2 = getVec(std::cin);
    }

    {
    Foo x;
    Foo y(x);
    Foo z(std::move(x));
    }

    {
    HasPtr hp, hp2;
    hp = hp2;
    hp = std::move(hp2);
    }
    return 0;
}

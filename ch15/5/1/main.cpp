#include <iostream>
#include <memory>
#include <vector>

class Base
{
    friend class Pal;

public:
    std::size_t size() const { return n; }

protected:
    int prot_mem;
    std::size_t n;
};

class Sneaky : public Base
{
    friend void clobber(Sneaky &);
    friend void clobber(Base &);
    //void f(Base &b) { b.prot_mem = 0; }
    int j;
};

class Pal
{
public:
    int f(Base b) { return b.prot_mem; }
    //int f2(Sneaky s) { return s.j; }
    int f3(Sneaky s) { return s.prot_mem; }
};

class D2 : public Pal
{
public:
    //int mem(Base b) { return b.prot_mem; }
};

void clobber(Sneaky &s) { s.j = s.prot_mem = 0; }
//void clobber(Base &b) { b.prot_mem = 0; }

class Derived : private Base
{
public:
    using Base::size;

protected:
    using Base::n;
};

class Derived2 : private Base
{
public:
    using Base::size;
    using Base::n;
};

int main()
{
    Base b;
    //b.n = 0;
    Derived2 d;
    d.n = 0;
    return 0;
}

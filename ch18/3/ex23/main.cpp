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
    A() { std::cout << "A()" << std::endl; }
};

class B : public A
{
public:
    B() { std::cout << "B()" << std::endl; }
};

class C : public B
{
public:
    C() { std::cout << "C()" << std::endl; }
};

class X
{
public:
    X() { std::cout << "X()" << std::endl; }
};

class Y
{
public:
    Y() { std::cout << "Y()" << std::endl; }
};

class Z : public X, public Y
{
public:
    Z() { std::cout << "Z()" << std::endl; }
};

class MI : public C, public Z
{
public:
    MI() { std::cout << "MI()" << std::endl; }
};

class D : public X, public C {};

int main()
{
    D *pd = new D;
    X *px = pd;
    A *pa = pd;
    B *pb = pd;
    C *pc = pd;
    return 0;
}

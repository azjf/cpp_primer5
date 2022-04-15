#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include <numeric>

class Base1
{
public:
    virtual void print() { std::cout << "Base1::print()" << std::endl; }
    virtual ~Base1() { std::cout << "Base1::~Base1()" << std::endl; }
};

class Base2
{
public:
    virtual void print() { std::cout << "Base2::print()" << std::endl; }
    virtual ~Base2() { std::cout << "Base2::~Base2()" << std::endl; }
};

class D1 : public Base1
{
public:
    void print() { std::cout << "D1::print()" << std::endl; }
};

class D2 : public Base2
{
public:
    void print() { std::cout << "D2::print()" << std::endl; }
};

class MI : public D1, public D2
{
public:
    void print() { std::cout << "MI::print()" << std::endl; }
};

int main()
{
    Base1 *pb1 = new MI;
    Base2 *pb2 = new MI;
    D1 *pd1 = new MI;
    D2 *pd2 = new MI;

    pb1->print();
    pd1->print();
    pd2->print();
    std::cout << std::endl;
    delete pb2;
    std::cout << std::endl;
    delete pd1;
    std::cout << std::endl;
    delete pd2;
    return 0;
}

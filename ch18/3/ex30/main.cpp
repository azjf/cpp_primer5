#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include <numeric>

class Class
{
public:
    Class() { std::cout << "Class::Class()" << std::endl; }
    Class(const Class &)
    { std::cout << "Class::Class(const Class &)" << std::endl; }
    Class(int) { std::cout << "Class::Class(int)" << std::endl; }
    virtual ~Class() { std::cout << "Class::~Class()" << std::endl; }
};

class Base : public Class
{
public:
    Base() { std::cout << "Base::Base()" << std::endl; }
    Base(const Base &)
    { std::cout << "Base::Base(const Base &)" << std::endl; }
    Base(int i) : Class(i) { std::cout << "Base::Base(int)" << std::endl; }
    virtual ~Base() { std::cout << "Base::~Base()" << std::endl; }
};

class D1 : virtual public Base
{
public:
    D1() { std::cout << "D1::D1()" << std::endl; }
    D1(const D1 &)
    { std::cout << "D1::D1(const D1 &)" << std::endl; }
    D1(int i) : Base(i) { std::cout << "D1::D1(int)" << std::endl; }
    virtual ~D1() { std::cout << "D1::~D1()" << std::endl; }
};

class D2 : virtual public Base
{
public:
    D2() { std::cout << "D2::D2()" << std::endl; }
    D2(const D2 &)
    { std::cout << "D2::D2(const D2 &)" << std::endl; }
    D2(int i) : Base(i) { std::cout << "D2::D2(int)" << std::endl; }
    virtual ~D2() { std::cout << "D2::~D2()" << std::endl; }
};

class MI : public D1, public D2
{
public:
    MI() { std::cout << "MI::MI()" << std::endl; }
    MI(const MI &)
    { std::cout << "MI::MI(const MI &)" << std::endl; }
    MI(int i) : Base(i), D1(i), D2(i)
    { std::cout << "MI::MI(int)" << std::endl; }
    virtual ~MI() { std::cout << "MI::~MI()" << std::endl; }
};

class Final : public MI, public Class
{
public:
    Final() { std::cout << "Final::Final()" << std::endl; }
    Final(const Final &)
    { std::cout << "Final::Final(const Final &)" << std::endl; }
    Final(int i) : Base(i), MI(i), Class(i)
    { std::cout << "Final::Final(int)" << std::endl; }
    virtual ~Final() { std::cout << "Final::~Final()" << std::endl; }
};


int main()
{
    Final f1;
    std::cout << std::endl;
    Final f2(1);
    std::cout << std::endl;
    Final f3(f2);
    std::cout << std::endl;
    return 0;
}

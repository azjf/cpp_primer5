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
    virtual ~Class() { std::cout << "Class::~Class()" << std::endl; }
};

class Base : public Class
{
public:
    Base() { std::cout << "Base::Base()" << std::endl; }
    virtual ~Base() { std::cout << "Base::~Base()" << std::endl; }
};

class D1 : virtual public Base
{
public:
    D1() { std::cout << "D1::D1()" << std::endl; }
    virtual ~D1() { std::cout << "D1::~D1()" << std::endl; }
};

class D2 : virtual public Base
{
public:
    D2() { std::cout << "D2::D2()" << std::endl; }
    virtual ~D2() { std::cout << "D2::~D2()" << std::endl; }
};

class MI : public D1, public D2
{
public:
    MI() { std::cout << "MI::MI()" << std::endl; }
    virtual ~MI() { std::cout << "MI::~MI()" << std::endl; }
};

class Final : public MI, public Class
{
public:
    Final() { std::cout << "Final::Final()" << std::endl; }
    virtual ~Final() { std::cout << "Final::~Final()" << std::endl; }
};


int main()
{
    Final f;
    std::cout << std::endl;

    Base *pb;
    Class *pc;
    MI *pmi;
    D2 *pd2;

    //pb = new Class();
    //pc = new Final();
    //pmi = pb;
    pd2 = pmi;
    return 0;
}

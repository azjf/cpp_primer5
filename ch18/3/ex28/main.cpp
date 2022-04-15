#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include <numeric>

struct Base
{
    void bar(int) { std::cout << "Base::bar(int)" << std::endl; }

protected:
    int ival;
};

struct Derived1 : virtual public Base
{
    void bar(char) { std::cout << "Derived1::bar(char)" << std::endl; }
    void foo(char) { std::cout << "Derived1::foo(char)" << std::endl; }

protected:
    char cval;
};

struct Derived2 : virtual public Base
{
    void foo(int) { std::cout << "Derived2::foo(int)" << std::endl; }

protected:
    int ival;
    char cval;
};

class VMI : public Derived1, public Derived2 {};

int main()
{
    VMI vmi;
    vmi.Derived1::Base::bar(0);
    vmi.bar('\0');
    vmi.Derived1::foo('c');
    vmi.Derived2::foo(0);

    //vmi.Derived1::Base::ival = 0;
    //vmi.Derived1::cval = '\0';
    //vmi.Derived2::ival = 0;
    //vmi.Derived2::cval = '\0';
    return 0;
}

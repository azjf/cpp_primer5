#include <iostream>
#include <memory>
#include <vector>

class Base {};

class Derived : public Base {};

void f1(Base &) {}
void f2(Base *) {}

int main()
{
    Derived d;
    f1(d);
    f2(&d);
    return 0;
}

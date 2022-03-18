#include <iostream>
#include <memory>
#include <vector>

class Base {};

//class Derived : public Derived {};
class Derived2 : private Base {};
//class Derived3 : public Base;

int main()
{
    return 0;
}

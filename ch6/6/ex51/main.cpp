#include <iostream>

void f()
{
    std::cout << "f()" << std::endl;
}

void f(int v)
{
    std::cout << "f(int)" << std::endl;
}

void f(int v1, int v2)
{
    std::cout << "f(int, int)" << std::endl;
}

void f(double v1, double v2 = 3.14)
{
    std::cout << "f(double, double)" << std::endl;
}

int main()
{
    f(5.6);
    //f(2.56, 42);
    f(42);
    f(42, 0);
    f(2.56, 3.14);
    return 0;
}

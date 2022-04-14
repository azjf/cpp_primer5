#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include <numeric>

namespace primerLib
{
void compute() { std::cout << "primerLib::compute()" << std::endl; }

void compute(const void *)
{ std::cout << "primerLib::compute(const void *)" << std::endl; }
}

//using primerLib::compute;

void compute(int) { std::cout << "compute(int)" << std::endl; }

void compute(double, double = 3.4)
{ std::cout << "compute(double, double = 3.4" << std::endl; }

void compute(char *, char * = 0)
{ std::cout << "compute(char * char * = 0)" << std::endl; }

void f()
{
    using primerLib::compute;
    compute(0);
}

int main()
{
    f();
    return 0;
}

#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include <numeric>

#include "StrVec.h"

void *operator new(std::size_t size)
{
    std::cout << "global: operator new(std::size)" << std::endl;
    if (void *mem = std::malloc(size)) {
        return mem;
    } else {
        throw std::bad_alloc();
    }
}

void operator delete(void *mem) noexcept
{
    std::cout << "global: operator delete(void *)" << std::endl;
    std::free(mem);
}

int main()
{
    StrVec sv;
    sv.push_back("hello");
    std::cout << std::endl;

    StrVec *psv = new StrVec();
    delete psv;
    std::cout << std::endl;

    std::string *ps = new std::string("hello");
    delete ps;
    std::cout << std::endl;
    return 0;
}

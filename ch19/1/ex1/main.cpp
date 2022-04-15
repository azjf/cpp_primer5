#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include <numeric>

void *operator new(std::size_t size)
{
    std::cout << "operator new(std::size)" << std::endl;
    if (void *mem = std::malloc(size)) {
        return mem;
    } else {
        throw std::bad_alloc();
    }
}

void operator delete(void *mem) noexcept
{
    std::cout << "operator delete(void *)" << std::endl;
    std::free(mem);
}

int main()
{
    std::string *sp = new std::string("hello");
    delete sp;
    return 0;
}

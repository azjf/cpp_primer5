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
    {
    std::string *sp = new std::string("a Value");
    std::string *arr = new std::string[10];
    delete sp;
    delete []arr;
    std::cout << std::endl;

    new(std::nothrow) int(0);

    int iarr[10];
    new(iarr) int[10]{1, 2, 3};
    std::cout << iarr[0] << iarr[1] << iarr[2] << std::endl;
    iarr[0] = 0;
    new(iarr) char('a');
    std::cout << iarr[0] << std::endl;
    }

    std::string *sp = new std::string("a Value");
    //sp->~string();
    return 0;
}

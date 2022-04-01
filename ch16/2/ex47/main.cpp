#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <type_traits>
#include <cstring>
#include "Blob.h"
#include "BlobPtr.h"


void f(int v1, int &v2)
{
    std::cout << v1 << " " << ++v2 << std::endl;
}

void g(int &&i, int &j)
{
    std::cout << i << " " << j << std::endl;
}

template <typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2)
{
    f(std::forward<T2>(t2), std::forward<T1>(t1));
}

int main()
{
    int i = 0;
    flip(f, i, 42);
    flip(g, i, 42);
    return 0;
}

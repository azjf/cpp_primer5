#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <cstring>

template <typename T> void g(T &&val) { std::vector<T> v; }

int main()
{
    //std::vector<int&> ivec;
    //std::vector<int&&> ivec;
    g(42);
    return 0;
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <list>
#include <type_traits>
#include <cstring>

template <typename T>
std::ostream &print(std::ostream &os, const T &t)
{
    return os << t;
}

template <typename T, typename ...Args>
std::ostream &print(std::ostream &os, const T &t, const Args &...rest)
{
    os << t << " ";
    return print(os, rest...);
}

class A {};

int main()
{
    print(std::cout, A(), 1) << std::endl;
    return 0;
}

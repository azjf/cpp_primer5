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

int main()
{
    int i = 0;
    double d = 3.14;
    long l = 1234;
    char c = 'a';
    std::string s = "how now brown cow";
    print(std::cout, i) << std::endl;
    print(std::cout, i, d) << std::endl;
    print(std::cout, i, d, l, c, s) << std::endl;
    return 0;
}

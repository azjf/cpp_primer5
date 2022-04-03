#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <list>
#include <type_traits>
#include <cstring>

template <typename... Args>
void g(const Args &...args)
{
    std::cout << sizeof...(Args) << std::endl;
    std::cout << sizeof...(args) << std::endl;
}

int main()
{
    int i = 0;
    double d = 3.14;
    std::string s = "how now brown cow";
    g(i, s, 42, d);
    g(s, 43, "hi");
    g(d, s);
    g("hi");
    return 0;
}

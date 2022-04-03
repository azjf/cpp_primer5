#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <list>
#include <type_traits>
#include <cstring>

#include "StrVec.h"

template <typename T, typename... Args>
void foo(const T &t, const Args &...rest) {}

template <typename... Args>
void g(const Args &...args)
{
    std::cout << sizeof...(Args) << std::endl;
    std::cout << sizeof...(args) << std::endl;
}

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

template <typename T> std::string debug_rep(const T &t);
template <typename T> std::string debug_rep(T *p);
std::string debug_rep(const std::string &);

template <typename T> std::string debug_rep(const T &t)
{
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

template <typename T> std::string debug_rep(T *p)
{
    std::ostringstream ret;
    ret << "pointer: " << p;
    if (p) {
        ret << " " << debug_rep(*p);
    } else {
        ret << " null pointer";
    }
    return ret.str();
}

std::string debug_rep(const std::string &s)
{
    return '"' + s + '"';
}

std::string debug_rep(char *p)
{
    return debug_rep(std::string(p));
}

std::string debug_rep(const char *p)
{
    return debug_rep(std::string(p));
}

template <typename ...Args>
std::ostream &errorMsg(std::ostream &os, const Args &...rest)
{
    //return print(os, debug_rep(rest)...);
    return print(os, debug_rep(rest...));
}

class Code
{
public:
    int num() { return 1; }
};

int main()
{
    int i = 0;
    double d = 3.14;
    std::string s = "how now brown cow";
    foo(i, s, 42, d);
    foo(s, 43, "hi");
    foo(d, s);
    foo("hi");

    print(std::cout, i, s, 42);

    std::string fcnName("fcnName"), otherData("otherData"), item("item");
    Code code;
    print(std::cerr, fcnName, code.num(), otherData, "other", item);

    StrVec svec;
    svec.emplace_back(10, 'c');
    std::string s1("the"), s2(" end");
    svec.emplace_back(s1 + s2);
    std::cout << '\n' << svec[0] << " " << svec[1] << std::endl;
    return 0;
}

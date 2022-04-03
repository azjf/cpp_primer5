#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <list>
#include <type_traits>
#include <cstring>

template <typename T> std::string debug_rep(const T &t);
template <typename T> std::string debug_rep(T *p);
template <> std::string debug_rep(char *);
template <> std::string debug_rep(const char *);

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

template <> std::string debug_rep(char *p)
{
    return debug_rep(std::string(p));
}

template <> std::string debug_rep(const char *p)
{
    return debug_rep(std::string(p));
}

int main()
{
    std::string s("hi");
    std::cout << debug_rep(s) << std::endl;
    std::cout << debug_rep(&s) << std::endl;

    const std::string *sp = &s;
    std::cout << debug_rep(sp) << std::endl;

    std::cout << debug_rep(s) << std::endl;
    std::cout << debug_rep("hi world!") << std::endl;
    return 0;
}

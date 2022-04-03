#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <list>
#include <unordered_set>
#include <type_traits>
#include <cstring>

#include "Sales_data.h"

template <typename T> int compare(const T &, const T &);

//template <std::size_t N, std::size_t M>
template <unsigned N, unsigned M>

int compare(const char (&)[N], const char (&)[M]);
template <> int compare(const char * const &, const char * const &);

template <typename T>
int compare(const T &v1, const T &v2)
{
    if (v1 < v2) {
        return -1;
    }
    if (v2 < v1) {
        return 1;
    }
    return 0;
}

template<unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M])
{
    return std::strcmp(p1, p2);
}

template <>
int compare(const char * const &p1, const char * const &p2)
{
    return std::strcmp(p1, p2);
}

template <class T> struct remove_reference
{
    typedef T type;
};

template <class T> struct remove_reference<T &>
{
    typedef T type;
};

template <class T> struct remove_reference<T &&>
{
    typedef T type;
};

template <typename T> struct Foo
{
    Foo(const T &t = T()) : mem(t) {}
    void Bar() {}
    T mem;
};

template <>
void Foo<int>::Bar() {}

int main()
{
    const char *p1 = "hi", *p2 = "mom";
    compare(p1, p2);
    compare("hi", "mom");

    std::unordered_multiset<Sales_data> SDset;

    int i;
    remove_reference<decltype(42)>::type a;
    remove_reference<decltype(i)>::type b;
    remove_reference<decltype(std::move(i))>::type c;

    Foo<std::string> fs;
    fs.Bar();
    Foo<int> fi;
    fi.Bar();
    return 0;
}

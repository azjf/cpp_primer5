#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <type_traits>
#include <cstring>
#include "Blob.h"
#include "BlobPtr.h"

template <typename T> T fobj(T t1, T) { return t1; }
template <typename T> T fref(const T &t1, const T &) { return t1; }

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

template <typename A, typename B>
int flexibleCompare(const A &v1, const B &v2)
{
    if (v1 < v2) {
        return -1;
    }
    if (v2 < v1) {
        return 1;
    }
    return 0;
}

template <typename T>
std::ostream &print(std::ostream &os, const T &obj)
{
    return os << obj;
}

template <typename T1, typename T2, typename T3>
T1 sum(T2, T3) { return 0; }

template <typename T1, typename T2, typename T3>
T3 alternative_sum(T2, T1) { return 0; }

template <typename It>
auto fcn(It beg, It end) -> decltype(*beg)
{
    return *beg;
}

template <typename It>
auto fcn2(It beg, It end)
    -> typename std::remove_reference<decltype(*beg)>::type
{
    return *beg;
}

void func(int (*)(const std::string &, const std::string &)) {}
void func(int (*)(const int &, const int &)) {}

template <typename T> void f1(T &) {}
template <typename T> void f2(const T &) {}
template <typename T> T fcn(const T &t) { return t + 1; }
template <typename T> void f3(T &&val) {}
template <typename T> void f32(T &&val)
{
    T t = val;
    t = fcn(t);
    if (val == t) {
        std::cout << "lvalue" << std::endl;
    }
}
template <typename T> void f(T &&);
template <typename T> void f(const T &);

template <typename T>
typename std::remove_reference<T>::type &&move(T &&t)
{
    return static_cast<typename std::remove_reference<T>::type &&>(t);
}

template <typename F, typename T1, typename T2>
void flip1(F f, T1 t1, T2 t2)
{
    f(t2, t1);
}

void ff(int v1, int &v2)
{
    std::cout << v1 << " " << ++v2 << std::endl;
}

template <typename F, typename T1, typename T2>
void flip2(F f, T1 &&t1, T2 &&t2)
{
    f(t2, t1);
}

void g(int &&i, int &j)
{
    std::cout << i << " " << j << std::endl;
}

template <typename T> void finalFcn(T &&arg) {}
template <typename Type> void intermediary(Type &&arg)
{
    finalFcn(std::forward<Type>(arg));
}

template <typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2)
{
    f(std::forward<T2>(t2), std::forward<T1>(t1));
}

int main()
{
    {
    std::string s1("a value");
    const std::string s2("another value");
    fobj(s1, s2);
    fref(s1, s2);

    int a[10], b[42];
    fobj(a, b);
    //fref(a, b);
    }

    {
    long lng;
    //compare(lng, 1024);
    flexibleCompare(lng, 1024);
    compare<long>(lng, 1024);
    compare<int>(lng, 1024);

    print(std::cout, 42);
    std::ofstream f("output");
    print(f, 10);
    }

    {
    int i = 0;
    long lng = 0;
    //long long val3 = sum(i, lng);
    auto val3 = sum<long long>(i, lng);
    }

    {
    int i = 0;
    long lng = 0;
    //auto val3 = alternative_sum<long long>(i, lng);
    auto val2 = alternative_sum<long long, int, long>(i, lng);
    }

    {
    std::vector<int> vi = {1, 2, 3, 4, 5};
    Blob<std::string> ca = {"hi", "bye"};
    auto &i = fcn(vi.begin(), vi.end());
    auto &s = fcn(ca.begin(), ca.end());
    }

    {
    int (*pf1)(const int &, const int &) = compare;
    //func(compare);
    func(compare<int>);

    int i = 0;
    const int ci = 0;
    f1(i);
    f1(ci);
    //f1(5);
    f2(i);
    f2(ci);
    f2(5);
    f3(42);
    f3(i);
    f3(ci);
    //void f3<int&>(int &);
    f32(i);
    f32(1);
    }

    {
    std::string s1("hi!"), s2;
    s2 = std::move(std::string("bye"));
    std::string &&move(std::string &&t);
    s2 = std::move(s1);
    std::string &&move(std::string &t);
    }

    {
    int i = 0, j = 0;
    ff(42, i);
    flip1(ff, j, 42);
    flip2(ff, j, 42);
    flip2(ff, j, 42);
    //flip2(g, j, 42);
    flip(g, j, 42);
    }
    return 0;
}

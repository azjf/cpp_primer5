#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <cstring>
#include "Sales_data.h"
#include "Blob.h"
#include "BlobPtr.h"

int compare(const std::string &v1, const std::string &v2)
{
    if (v1 < v2) {
        return -1;
    }
    if (v2 < v1) {
        return 1;
    }
    return 0;
}

int compare(const double &v1, const double &v2)
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

template <typename T> T foo(T *p)
{
    T tmp = *p;
    return tmp;
}

//template <typename T, U> T calc(const T &, const U &);
template <typename T, class U> T calc(const T &, const U &);

template<unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M])
{
    return std::strcmp(p1, p2);
}

template <typename T> inline T min(const T &, const T &);
//inline template <typename T> T min(const T &, const T &);

template <typename T>
int compare2(const T &v1, const T &v2)
{
    if (std::less<T>()(v1, v2)) {
        return -1;
    }
    if (std::less<T>()(v2, v1)) {
        return 1;
    }
    return 0;
}

template <typename T> class Pal;
class C
{
    friend class Pal<C>;
    template <typename T> friend class Pal2;
};
template <typename T> class C2
{
    friend class Pal<T>;
    template <typename X> friend class Pal2;
    friend class Pal3;
};

template <typename Type> class Bar
{
    friend Type;
};

template <typename T> using twin = std::pair<T, T>;
template <typename T> using partNo = std::pair<T, unsigned>;

template <typename T> class Foo
{
public:
    static std::size_t count() { return ctr; }

private:
    static std::size_t ctr;
};
template <typename T> std::size_t Foo<T>::ctr = 0;

template <typename Foo> Foo calc(const Foo &a, const Foo &b)
{
    Foo tmp = a;
    return tmp;
}

typedef double A;
template <typename A, typename B> void f(A a, B b)
{
    A tmp = a;
    //double B;
}
//template <typename V, typename V> void f();

template <typename T> int compare(const T &, const T &);
template <typename T> class Blob;
template <typename T> T calc(const T &, const T &);
template <typename U> U calc(const U &, const U &);
template <typename Type>
Type calc2(const Type &a, const Type &b) { return a; }

template <typename T>
typename T::value_type top(const T &c)
{
    //T::size_type * p;
    if (!c.empty()) {
        return c.back();
    } else {
        return typename T::value_type();
    }
}

template <typename T, typename F = std::less<T>>
int compare3(const T &v1, const T &v2, F f = F())
{
    if (f(v1, v2)) {
        return -1;
    }
    if (f(v2, v1)) {
        return 1;
    }
    return 0;
}

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

template <class T = int> class Numbers
{
public:
    Numbers(T v = 0) : val(v) {}

private:
    T val;
};

class DebugDelete
{
public:
    DebugDelete(std::ostream &s = std::cerr) : os(s) {}
    template <typename T> void operator()(T *p) const
    { os << "deleting unique_ptr" << std::endl; delete p; }

private:
    std::ostream &os;
};

int main()
{
    std::cout << compare(1, 0) << std::endl;
    std::vector<int> vec1{1, 2, 3}, vec2{4, 5, 6};
    std::cout << compare(vec1, vec2) << std::endl;
    compare("hi", "mom");

    Sales_data data1, data2;
    //std::cout << compare(data1, data2) << std::endl;

    Blob<int> ia;
    Blob<int> ia2 = {0, 1, 2, 3, 4};
    Blob<std::string> names;
    Blob<double> prices;

    Blob<std::string> articles = {"a", "an", "the"};

    Blob<int> squares = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (std::size_t i = 0; i != squares.size(); ++i) {
        squares[i] = i * i;
    }

    typedef Blob<std::string> StrBlob;
    StrBlob sb{"hello", "world"};

    twin<std::string> authors;
    twin<int> win_loss;
    twin<double> area;

    partNo<std::string> books;
    //partNo<Vehicle> cars;
    //partNo<Student> kids;

    Foo<std::string> fs;
    Foo<int> fi, fi2, fi3;
    auto ct = Foo<int>::count();
    ct = fi.count();
    //ct = Foo::count();

    top(std::vector<int>());

    bool i = compare3(0, 42);
    Sales_data item1(std::cin), item2(std::cin);
    bool j = compare3(item1, item2, compareIsbn);

    Numbers<long double> lots_of_prcecision;
    Numbers<> average_precision;

    {
    double *p = new double;
    DebugDelete d;
    d(p);
    int *ip = new int;
    DebugDelete()(ip);
    }
    {
    std::unique_ptr<int, DebugDelete> p(new int, DebugDelete());
    std::unique_ptr<std::string, DebugDelete>
        sp(new std::string, DebugDelete());
    }

    {
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<long> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<const char *> w = {"now", "is", "the", "time"};
    Blob<int> a1(std::begin(ia), std::end(ia));
    Blob<int> a2(vi.begin(), vi.end());
    Blob<std::string> a3(w.begin(), w.end());
    }
    return 0;
}

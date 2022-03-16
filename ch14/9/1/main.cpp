#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

class SmallInt
{
public:
    SmallInt(int i = 0) : val(i)
    {
        if (i < 0 || i > 255) {
            throw std::out_of_range("Bad SamllInt value");
        }
    }

    operator int() const { return val; }
    //int operator int() const;
    //operator int(int = 0) const;
    //operator int*() const { return 42; }

private:
    std::size_t val;
};

class SmallInt2
{
public:
    SmallInt2(int i = 0) : val(i)
    {
        if (i < 0 || i > 255) {
            throw std::out_of_range("Bad SamllInt value");
        }
    }

    explicit operator int() const { return val; }

private:
    std::size_t val;
};

struct B;

struct A
{
    A() = default;
    A(const B &) {}
};

struct B
{
    operator A() const { return A(); }
};

A f(const A &) { return A(); }

struct A2
{
    A2(int = 0) {}
    A2(double) {}
    operator int() const { return 0; }
    operator double() const { return 0; }
};

void f2(long double) {}

struct C
{
    C(int) {}
};

struct D
{
    D(int) {}
};

void manip(const C &) {}
void manip(const D &) {}

struct E
{
    E(double) {}
};

void manip2(const C &) {}
void manip2(const D &) {}

class SmallInt3
{
    friend SmallInt3 operator+(const SmallInt3 &, const SmallInt3 &);

public:
    SmallInt3(int i = 0) : val(i)
    {
        if (i < 0 || i > 255) {
            throw std::out_of_range("Bad SamllInt value");
        }
    }

    operator int() const { return val; }
    //int operator int() const;
    //operator int(int = 0) const;
    //operator int*() const { return 42; }

private:
    std::size_t val;
};

SmallInt3 operator+(const SmallInt3 &lhs, const SmallInt3 &rhs)
    { return SmallInt3(lhs.val + rhs.val); }

int main()
{
    {
    SmallInt si;
    si = 4;
    si + 3;

    si = 3.14;
    si + 3.14;
    }

    {
    SmallInt2 si = 3;
    //si + 3;
    static_cast<int>(si) + 3;
    }

    {
    B b;
    //A a = f(b);
    A a1 = f(b.operator A());
    A a2 = f(A(b));
    }

    {
    A2 a;
    //f2(a);

    long lg;
    //A2 a2(lg);

    short s = 42;
    A2 a3(s);

    //manip(10);
    manip(C(10));
    
    //manip2(10);
    }

    {
    SmallInt3 s1, s2;
    SmallInt3 s3 = s1 + s2;
    //int i = s3 + 0;
    }
    return 0;
}

#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include <numeric>

struct Base1
{
    void print(int) const {}

protected:
    int ival;
    double dval;
    char cval;

private:
    int *id;
};

struct Base2
{
    void print(double) const {}

protected:
    double fval;

private:
    double dval;
};

struct Derived : public Base1
{
    void print(std::string) const {}

protected:
    std::string sval;
    double dval;
};

struct MI : public Derived, public Base2
{
    void print(std::vector<double>) {}

    void foo(double cval);

protected:
    int *ival;
    std::vector<double> dvec;
};

int ival;
double dval;

void MI::foo(double cval)
{
    int dval;

    dval = Base1::dval + Derived::dval;

    dvec.push_back(1);
    fval = dvec.back();

    sval = "abc";
    sval[0] = cval;
}

int main()
{
    MI mi;
    mi.foo(0);
    return 0;
}

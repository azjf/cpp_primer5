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

protected:
    int *ival;
    std::vector<double> dvec;
};

int main()
{
    MI mi;
    //mi.print(42);
    mi.Derived::Base1::print(42);
    mi.Base2::print(42);
    return 0;
}

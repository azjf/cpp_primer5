#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include <numeric>

#include "Sales_data.h"

void f() noexcept
{
    throw std::exception();
}

void recoup(int) noexcept {}
void alloc(int) {}

class Base
{
public:
    virtual double f1(double) noexcept;
    virtual int f2() noexcept(false);
    virtual void f3();
};

class Derived : public Base
{
public:
    //double f1(double) { return 0; }
    int f2() noexcept(false) { return 0; }
    void f3() noexcept {}
};

int main()
{
    //f();

    void recoup(int) noexcept;
    void recoup(int) throw();
    void recoup(int) noexcept(true);
    void recoup2(int) noexcept(false);

    int i = 1;
    std::cout << noexcept(recoup(i)) << std::endl;

    void e();
    std::cout << noexcept(e) << std::endl;

    void g();
    void f2() noexcept(noexcept(g()));

    void (*pf1)(int) noexcept = recoup;
    void (*pf2)(int) = recoup;
    //pf1 = alloc;
    pf2 = alloc;

    Sales_data item1, item2, sum;
    while (std::cin >> item1 >> item2) {
        try {
            sum = item1 + item2;
        } catch (const isbn_mismatch &e) {
            std::cerr << e.what() << ": left isbn(" << e.left
                << ") right isbn(" << e.right << ")" << std::endl;
        }
    }
    return 0;
}

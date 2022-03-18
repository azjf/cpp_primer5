#include <iostream>
#include <memory>
#include <vector>
#include "Quote.h"
#include "Bulk_quote.h"

double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
        << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

struct B
{
    virtual void f1(int) const;
    virtual void f2();
    void f3();
};

struct D1 : B
{
    void f1(int) const override;
    //void f2(int) override;
    //void f3() override;
    //void f4() override;
};

struct D2 : B
{
    void f1(int) const final;
};

struct D3 : D2
{
    void f2() override;
    //void f1(int) const;
};

int main()
{
    {
    Quote base("0-201-82470-1", 50);
    print_total(std::cout, base, 10);
    Bulk_quote derived("0-201-82470-1", 50, 5, .19);
    print_total(std::cout, derived, 10);
    
    base = derived;
    base.net_price(20);

    Quote *baseP = &derived;
    double undiscounted = baseP->Quote::net_price(42);
    }
    return 0;
}

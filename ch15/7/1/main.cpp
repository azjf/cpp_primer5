#include <iostream>
#include <memory>
#include <vector>
#include "Quote.h"
#include "Bulk_quote.h"
#include "Disc_quote.h"

double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
        << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

class B
{
public:
    B() = default;
    B(const B &) = delete;
};

class D : public B
{
};

class D2 : public B
{
public:
    D2() = default;
    D2(const D2 &) {}
};

int main()
{
    {
    Quote *itemP = new Quote;
    delete itemP;
    itemP = new Bulk_quote;
    delete itemP;

    D d;
    //D d2(d);
    //D d3(std::move(d));
    D2 d21;
    D2 d22(d21);
    }
    return 0;
}

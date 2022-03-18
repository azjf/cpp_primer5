#include <iostream>
#include <memory>
#include <vector>
#include "Bulk_quote.h"

double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
        << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

int main()
{
    Bulk_quote quote("isbn", 1.1, 10, 0.1);
    print_total(std::cout, quote, 20);
    return 0;
}

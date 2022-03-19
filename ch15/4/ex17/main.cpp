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

int main()
{
    //Disc_quote discounted;
    return 0;
}

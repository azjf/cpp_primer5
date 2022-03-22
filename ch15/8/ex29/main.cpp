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
    std::vector<std::shared_ptr<Quote>> basket{
            std::make_shared<Quote>("0-201-82470-1", 50),
            std::make_shared<Quote>("0-201-82470-1", 50),
            std::make_shared<Quote>("0-201-82470-1", 50),
    };
    double net_price = 0;
    for (const auto &p : basket) {
        net_price += p->net_price(50);
    }
    std::cout << net_price << std::endl;
    return 0;
}

#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include "Quote.h"

class Bulk_quote : public Quote
{
public:
    double net_price(std::size_t) const override
        { std::cout << "Bulk_quote::net_price" << std::endl; return 0; }
};
#endif

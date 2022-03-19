#ifndef BULK_QUOTE2_H
#define BULK_QUOTE2_H
#include "Disc_quote.h"

class Bulk_quote2 : public Disc_quote
{
public:
    Bulk_quote2() = default;
    Bulk_quote2(const std::string &, double, std::size_t, std::size_t, double);

    double net_price(std::size_t) const override;

private:
    std::size_t max_qty = 0;
};
#endif

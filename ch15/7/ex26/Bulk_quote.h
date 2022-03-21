#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include "Disc_quote.h"

class Bulk_quote : public Disc_quote
{
public:
    Bulk_quote();
    Bulk_quote(const std::string &, double, std::size_t, double);
    Bulk_quote(const Bulk_quote &);
    Bulk_quote(Bulk_quote &&);
    Bulk_quote &operator=(const Bulk_quote &);
    Bulk_quote &operator=(Bulk_quote &&);
    ~Bulk_quote();

    double net_price(std::size_t) const override;
};
#endif

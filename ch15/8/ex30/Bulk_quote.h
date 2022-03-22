#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include "Disc_quote.h"

class Bulk_quote : public Disc_quote
{
public:
    using Disc_quote::Disc_quote;
    //Bulk_quote() = default;
    //Bulk_quote(const std::string &book, double price, std::size_t qty,
    //        double disc) : Disc_quote(book, price, qty, disc) {}

    double net_price(std::size_t) const override;

    Bulk_quote *clone() const & override { return new Bulk_quote(*this); }
    Bulk_quote *clone() && override { return new Bulk_quote(std::move(*this)); }
};
#endif

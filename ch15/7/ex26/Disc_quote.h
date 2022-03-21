#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H
#include "Quote.h"

class Disc_quote : public Quote
{
public:
    Disc_quote();
    Disc_quote(const std::string &, double, std::size_t, double);
    Disc_quote(const Disc_quote &);
    Disc_quote(Disc_quote &&);
    Disc_quote &operator=(const Disc_quote &);
    Disc_quote &operator=(Disc_quote &&);
    ~Disc_quote();

    double net_price(std::size_t) const = 0;
    std::pair<std::size_t, double> discount_policy() const
        { return {quantity, discount}; }

protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};
#endif

#include "Bulk_quote2.h"

Bulk_quote2::Bulk_quote2(const std::string &book, double p, std::size_t qty1,
        std::size_t qty2, double disc) :
    Disc_quote(book, p, qty2, disc), max_qty(qty2) {}

double Bulk_quote2::net_price(std::size_t cnt) const
{
    if (cnt > max_qty) {
        return max_qty * (1 - discount) * price + (cnt - max_qty) * price;
    } else if (cnt >= quantity) {
        return cnt * (1 - discount) * price;
    } else {
        return cnt * price;
    }
}

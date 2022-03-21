#include "Bulk_quote.h"

Bulk_quote::Bulk_quote()
{
    std::cout << "Bulk_quote()" << std::endl;
}

Bulk_quote::Bulk_quote(const std::string &book, double price, std::size_t qty,
        double disc) : Disc_quote(book, price, qty, disc)
{
    std::cout << "Bulk_quote(const std::string &, double, std::size_t, double)"
        << std::endl;
}

Bulk_quote::Bulk_quote(const Bulk_quote &q) : Disc_quote(q)
{
    std::cout << "Bulk_quote(const Bulk_quote &)" << std::endl;
}

Bulk_quote::Bulk_quote(Bulk_quote &&q) : Disc_quote(std::move(q))
{
    std::cout << "Bulk_quote(Bulk_quote &&)" << std::endl;
}

Bulk_quote &Bulk_quote::operator=(const Bulk_quote &rhs)
{
    Disc_quote::operator=(rhs);
    std::cout << "operator=(const Bulk_quote &)" << std::endl;
    return *this;
}

Bulk_quote &Bulk_quote::operator=(Bulk_quote &&rhs)
{
    Disc_quote::operator=(std::move(rhs));
    std::cout << "operator=(Bulk_quote &&)" << std::endl;
    return *this;
}

Bulk_quote::~Bulk_quote()
{
    std::cout << "~Bulk_quote()" << std::endl;
}

double Bulk_quote::net_price(std::size_t cnt) const
{
    if (cnt >= quantity) {
        return cnt * (1 - discount) * price;
    } else {
        return cnt * price;
    }
}

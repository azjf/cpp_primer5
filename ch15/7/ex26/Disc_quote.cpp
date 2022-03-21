#include "Disc_quote.h"

Disc_quote::Disc_quote()
{
    std::cout << "Disc_quote()" << std::endl;
}

Disc_quote::Disc_quote(const std::string &book, double price, std::size_t qty,
        double disc) : Quote(book, price), quantity(qty), discount(disc)
{
    std::cout << "Disc_quote(const std::string &, double, std::size_t, double)"
        << std::endl;
}

Disc_quote::Disc_quote(const Disc_quote &q) :
    Quote(q), quantity(q.quantity), discount(q.discount)
{
    std::cout << "Disc_quote(const Disc_quote &)" << std::endl;
}

Disc_quote::Disc_quote(Disc_quote &&q) :
    Quote(std::move(q)), quantity(q.quantity), discount(q.discount)
{
    std::cout << "Disc_quote(Disc_quote &&)" << std::endl;
}

Disc_quote &Disc_quote::operator=(const Disc_quote &rhs)
{
    Quote::operator=(rhs);
    quantity = rhs.quantity;
    discount = rhs.discount;
    std::cout << "operator=(const Disc_quote &)" << std::endl;
    return *this;
}

Disc_quote &Disc_quote::operator=(Disc_quote &&rhs)
{
    Quote::operator=(std::move(rhs));
    quantity = rhs.quantity;
    discount = rhs.discount;
    std::cout << "operator=(Disc_quote &&)" << std::endl;
    return *this;
}

Disc_quote::~Disc_quote()
{
    std::cout << "~Disc_quote()" << std::endl;
}

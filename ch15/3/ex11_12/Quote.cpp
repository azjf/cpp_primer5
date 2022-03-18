#include "Quote.h"

std::ostream &Quote::debug() const
{
    return std::clog << "bookNo: " << bookNo << ", price: " << price;
}

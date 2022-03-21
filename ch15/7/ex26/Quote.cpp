#include "Quote.h"

Quote::Quote() : bookNo(""), price(0)
{
    std::cout << "Quote()" << std::endl;
}

Quote::Quote(const std::string &book, double sales_price) :
    bookNo(book), price(sales_price)
{
    std::cout << "Quote(const std::string &, double)" << std::endl;
}

Quote::Quote(const Quote &q) : bookNo(q.bookNo), price(q.price)
{
    std::cout << "Quote(const Quote &)" << std::endl;
}

Quote::Quote(Quote &&q) : bookNo(q.bookNo), price(q.price)
{
    std::cout << "Quote(Quote &&)" << std::endl;
}

Quote &Quote::operator=(const Quote &rhs)
{
    bookNo = rhs.bookNo;
    price = rhs.price;
    std::cout << "operator=(const Quote &)" << std::endl;
    return *this;
}

Quote &Quote::operator=(Quote &&rhs)
{
    bookNo = rhs.bookNo;
    price = rhs.price;
    std::cout << "operator=(Quote &&)" << std::endl;
    return *this;
}

Quote::~Quote()
{
    std::cout << "~Quote()" << std::endl;
}

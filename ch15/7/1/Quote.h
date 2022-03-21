#ifndef QUOTE_H
#define QUOTE_H
#include <string>
#include <iostream>

class Quote
{
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price) :
        bookNo(book), price(sales_price) {}
    Quote(const Quote &) = default;
    Quote(Quote &&) = default;
    Quote &operator=(const Quote &) = default;
    Quote &operator=(Quote &&) = default;
    virtual ~Quote() = default;

    std::string isbn() const { return bookNo; }

    virtual double net_price(std::size_t n) const
        { return n * price;}

private:
    std::string bookNo;

protected:
    double price = 0.0;
};
#endif

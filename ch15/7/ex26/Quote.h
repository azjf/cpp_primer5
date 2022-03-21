#ifndef QUOTE_H
#define QUOTE_H
#include <string>
#include <iostream>

class Quote
{
public:
    Quote();
    Quote(const std::string &book, double sales_price);
    Quote(const Quote &);
    Quote(Quote &&);
    Quote &operator=(const Quote &);
    Quote &operator=(Quote &&);
    virtual ~Quote();

    std::string isbn() const { return bookNo; }

    virtual double net_price(std::size_t n) const
        { return n * price;}

private:
    std::string bookNo;

protected:
    double price = 0.0;
};
#endif

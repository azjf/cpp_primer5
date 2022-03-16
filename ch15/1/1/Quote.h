#ifndef QUOTE_H
#define QUOTE_H
#include <string>
#include <iostream>

class Quote
{
public:
    std::string isbn() const { return "isbn"; }
    virtual double net_price(std::size_t n) const
        { std::cout << "Quote::net_price" << std::endl; return 0; }

};
#endif

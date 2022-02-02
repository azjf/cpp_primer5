#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
#include <iostream>

struct Sales_data {
    Sales_data(const std::string &s, unsigned n, double p)
        : bookNo(s), numSold(n), price(p)
    { std::cout << "Sales_data(std::string &, unsigned, double)" << std::endl; }

    Sales_data() : Sales_data("", 0, 0)
    { std::cout << "Sales_data()" << std::endl; }

    Sales_data(const std::string &s) : Sales_data(s, 0, 0)
    { std::cout << "Sales_data(std::string &)" << std::endl; }

    Sales_data(std::istream &is);

    Sales_data &combine(const Sales_data &rhs);
    std::string isbn() const { return bookNo; }

    std::string bookNo;
    unsigned numSold = 0;
    double price = 0.0;
};

Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
std::istream &read(std::istream &is, Sales_data &item);
std::ostream &print(std::ostream &os, const Sales_data &item);

inline Sales_data::Sales_data(std::istream &is) : Sales_data()
{
    std::cout << "Sales_data(std::istream &)" << std::endl;
    read(is, *this);
}
#endif

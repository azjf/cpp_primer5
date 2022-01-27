#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
#include <iostream>

struct Sales_data {
    Sales_data &combine(const Sales_data &rhs);
    std::string isbn() const { return bookNo; }

    std::string bookNo;
    unsigned numSold = 0;
    double price = 0.0;
};

Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
std::istream &read(std::istream &is, Sales_data &item);
std::ostream &print(std::ostream &os, const Sales_data &item);
#endif

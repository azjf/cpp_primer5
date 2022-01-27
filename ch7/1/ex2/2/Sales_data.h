#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>

struct Sales_data {
    Sales_data &combine(const Sales_data &rhs);
    std::string isbn() const { return bookNo; }

    std::string bookNo;
    unsigned numSold = 0;
    double price = 0.0;
};
#endif

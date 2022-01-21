#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>

struct Sales_data {
    std::string isbn;
    unsigned numSold = 0;
    double price = 0.0;
};
#endif

#include <iostream>
#include <vector>
#include <set>
#include "Sales_data.h"

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

int main()
{
    std::set<Sales_data,
        bool (*)(const Sales_data &, const Sales_data &)>
        bookstore(compareIsbn);
    return 0;
}

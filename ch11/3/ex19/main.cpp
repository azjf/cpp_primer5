#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include "Sales_data.h"

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

int main()
{
    Sales_data s1;
    read(std::cin, s1);
    std::multiset<Sales_data,
        bool (*) (const Sales_data &lhs, const Sales_data &rhs)>
        bookstore(compareIsbn);
    bookstore.insert(s1);

    std::multiset<Sales_data,
        bool (*) (const Sales_data &lhs, const Sales_data &rhs)>::iterator
        mset_it = bookstore.begin();
    Sales_data s2 = *mset_it;
    return 0;
}

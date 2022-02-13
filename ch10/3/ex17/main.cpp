#include <iostream>
#include <algorithm>
#include <vector>
#include "Sales_data.h"

int main()
{
    std::vector<Sales_data> tvec;
    Sales_data trans;
    while (read(std::cin, trans)) {
        tvec.push_back(trans);
    }

    std::sort(tvec.begin(), tvec.end(),
            [] (const Sales_data &t1, const Sales_data &t2)
            { return t1.isbn() < t2.isbn(); });
    for (const auto &trans : tvec) {
        print(std::cout, trans) << std::endl;
    }
    return 0;
}

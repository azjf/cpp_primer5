#include <iostream>
#include "Sales_data.h"

int main()
{
    Sales_data total, cur;
    if (!(std::cin >> total.bookNo >> total.numSold >> total.price)) {
        return -1;
    }
    while (std::cin >> cur.bookNo >> cur.numSold >> cur.price) {
        total.combine(cur);
    }
    std::cout << cur.bookNo << " " << total.numSold
        << " " << total.numSold * total.price << std::endl;
    return 0;
}

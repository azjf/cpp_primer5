#include <iostream>
#include "Sales_data.h"

int main()
{
    Sales_data total, cur;
    if (!(std::cin >> total.bookNo >> total.numSold >> total.price)) {
        return -1;
    }
    while (std::cin >> cur.bookNo >> cur.numSold >> cur.price) {
        if (cur.bookNo == total.bookNo) {
            total.combine(cur);
        } else {
            std::cout << total.bookNo << ": " << total.numSold << std::endl;
            total = cur;
        }
    }
    std::cout << total.bookNo << ": " << total.numSold << std::endl;
    return 0;
}

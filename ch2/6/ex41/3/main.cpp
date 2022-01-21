#include <iostream>
#include "Sales_data.h"

int main()
{
    Sales_data cur;
    int totalCnt = 0;
    double totalRevenue = 0.0;
    while (std::cin >> cur.isbn >> cur.numSold >> cur.price) {
        totalCnt += cur.numSold;
        totalRevenue += cur.numSold * cur.price;
    }
    std::cout << cur.isbn << " " << totalCnt
        << " " << totalRevenue << std::endl;
    return 0;
}

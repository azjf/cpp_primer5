#include <iostream>
#include "Sales_data.h"

int main()
{
    Sales_data data1, data2;
    std::cin >> data1.isbn >> data1.numSold >> data1.price;
    std::cin >> data2.isbn >> data2.numSold >> data2.price;

    if (data1.isbn == data2.isbn) {
        double totalCnt = data1.numSold + data2.numSold;
        double totalRevenue = data1.numSold * data1.price +
            data2.numSold + data2.price;
        std::cout << data1.isbn << " "
            << totalCnt << " " << totalRevenue << std::endl;
    } else {
        std::cerr << "The ISBN must be the same" << std::endl;
        return -1;
    }
    return 0;
}

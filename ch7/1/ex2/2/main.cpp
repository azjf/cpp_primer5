#include <iostream>
#include "Sales_data.h"

int main()
{
    Sales_data data1, data2;
    std::cin >> data1.bookNo >> data1.numSold >> data1.price;
    std::cin >> data2.bookNo >> data2.numSold >> data2.price;

    if (data1.bookNo == data2.bookNo) {
        data1.combine(data2);
        std::cout << data1.isbn() << " "
            << data1.numSold << " " << data1.numSold * data1.price << std::endl;
    } else {
        std::cerr << "The bookNo must be the same" << std::endl;
        return -1;
    }
    return 0;
}

#include <iostream>
#include "Sales_data.h"

int main()
{
    Sales_data data1, data2;
    read(std::cin, data1);
    read(std::cin, data2);

    if (data1.bookNo == data2.bookNo) {
        data1.combine(data2);
        print(std::cout, data1) << std::endl;
    } else {
        std::cerr << "The bookNo must be the same" << std::endl;
        return -1;
    }
    return 0;
}

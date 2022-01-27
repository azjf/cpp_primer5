#include <iostream>
#include "Sales_data.h"

int main()
{
    Sales_data total, cur;
    if (!read(std::cin, total)) {
        std::cerr << "No data!" << std::endl;
        return -1;
    }
    while (read(std::cin, cur)) {
        if (cur.bookNo == total.bookNo) {
            total.combine(cur);
        } else {
            print(std::cout, total) << std::endl;
            total = cur;
        }
    }
    print(std::cout, total) << std::endl;
    return 0;
}

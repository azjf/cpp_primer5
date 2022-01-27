#include <iostream>
#include "Sales_data.h"

int main()
{
    Sales_data total, cur;
    if (!read(std::cin, total)) {
        return -1;
    }

    while (read(std::cin, cur)) {
        total.combine(cur);
    }
    print(std::cout, total) << std::endl;
    return 0;
}

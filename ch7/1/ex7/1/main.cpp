#include <iostream>
#include "Sales_data.h"

int main()
{
    Sales_data data;
    while (read(std::cin, data)) {
        print(std::cout, data) << std::endl;
    }
    return 0;
}

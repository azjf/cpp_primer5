#include <iostream>
#include <memory>
#include <vector>
#include "Sales_data.h"

int main()
{
    Sales_data sd;
    read(std::cin, sd);
    std::cout << sd << std::endl;
    return 0;
}

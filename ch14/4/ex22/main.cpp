#include <iostream>
#include <memory>
#include <vector>
#include "Sales_data.h"

int main()
{
    Sales_data sd1, sd2;
    std::cin >> sd1 >> sd2;
    std::cout << sd1 + sd2 << std::endl;
    std::cout << (sd1 == sd2 ? "true" : "false") << std::endl;
    sd1 += sd2;
    std::cout << sd1 << std::endl;

    sd1 = "hello";
    std::cout << sd1 << std::endl;
    return 0;
}

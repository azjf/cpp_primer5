#include <iostream>
#include <memory>
#include <vector>
#include "Sales_data.h"

int main()
{
    Sales_data sd;
    std::cin >> sd;
    std::string s = sd;
    double d = static_cast<double>(sd);
    std::cout << s << std::endl;
    std::cout << d << std::endl;
    return 0;
}

#include <iostream>
#include <memory>
#include <vector>
#include "StrVec.h"
#include "Sales_data.h"

int main()
{
    StrVec sv;
    sv = {"hello", "world"};

    Sales_data sd1, sd2;
    std::cin >> sd1 >> sd2;
    std::cout << sd1 + sd2 << std::endl;
    std::cout << (sd1 == sd2 ? "true" : "false") << std::endl;
    sd1 += sd2;
    std::cout << sd1 << std::endl;
    return 0;
}

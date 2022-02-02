#include <iostream>
#include "Sales_data.h"

int main()
{
    std::cout << "data1" << std::endl;
    Sales_data data1("hello", 1, 2);

    std::cout << "\ndata2" << std::endl;
    Sales_data data2;

    std::cout << "\ndata3" << std::endl;
    Sales_data data3("hello");

    std::cout << "\ndata4" << std::endl;
    Sales_data data4(std::cin);
    return 0;
}

#include <iostream>
#include "Sales_data.h"

int main()
{
    Sales_data data;
    while (std::cin >> data.isbn >> data.numSold >> data.price) {
        std::cout << data.isbn << " " << data.numSold << " "
            << data.price << std::endl;
    }
    return 0;
}

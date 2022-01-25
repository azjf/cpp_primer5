#include <iostream>
#include <stdexcept>
#include "Sales_item.h"

int main()
{
    Sales_item item1, item2;
    while (std::cin >> item1 >> item2) {
        try {
            if (item1.isbn() != item2.isbn()) {
                throw std::runtime_error("Data must refer to same ISBN");
            }
            std::cout << item1 + item2 << std::endl;
        } catch (std::runtime_error &err) {
            std::cout << err.what()
                << "\nTry Again? Enter y or n" << std::endl;
            char c;
            if (!(std::cin >> c) || c == 'n') {
                break;
            }
        }
    }
}

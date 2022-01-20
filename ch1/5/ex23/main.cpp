#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item currVal, val;
    if (!(std::cin >> val)) {
        return -1;
    }
    int cnt = 1;
    while (std::cin >> currVal) {
        if (currVal.isbn() == val.isbn()) {
            ++cnt;
        } else {
            std::cout << val.isbn() << ": " << cnt << std::endl;
            val = currVal;
            cnt = 1;
        }
    }
    std::cout << val.isbn() << ": " << cnt << std::endl;
    return 0;
}

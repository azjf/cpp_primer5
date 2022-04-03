#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <list>
#include <unordered_set>
#include <type_traits>
#include <cstring>

#include "Sales_data.h"

int main()
{
    std::unordered_multiset<Sales_data> sd_set;
    Sales_data item;
    while (std::cin >> item) {
        sd_set.insert(item);
    }

    //for (const auto &item : sd_set) {
    for (const Sales_data &item : sd_set) {
        std::cout << item << std::endl;
    }
    return 0;
}

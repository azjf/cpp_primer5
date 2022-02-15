#include <iostream>
#include <unordered_map>
#include "Sales_data.h"

size_t hasher(const Sales_data &sd)
{
    return std::hash<std::string>()(sd.isbn());
}

bool eqOp(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() == rhs.isbn();
}

int main()
{
    std::unordered_map<std::string, size_t> word_count;
    std::string word;
    while (std::cin >> word) {
        ++word_count[word];
    }
    for (const auto &w : word_count) {
        std::cout << w.first << " occurs " << w.second
            << ((w.second > 1) ? " times" : " time") << std::endl;
    }

    using SD_multiset =
        std::unordered_map<Sales_data, decltype(hasher) *, decltype(eqOp) *>;
    SD_multiset bookstore(42, hasher, eqOp);
    return 0;
}

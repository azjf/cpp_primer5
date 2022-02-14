#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include "Sales_data.h"

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

std::pair<std::string, int> process(std::vector<std::string> &v)
{
    if (!v.empty()) {
        return std::pair<std::string, int>(v.back(), v.back().size());
        return std::make_pair(v.back(), v.back().size());
        return {v.back(), v.back().size()};
    } else {
        return std::pair<std::string, int>();
        return {std::string(), 0};
    }
}

int main()
{
    std::map<std::string, size_t> word_count;
    std::set<std::string> exclude = {"the", "but", "and", "or", "an", "a",
        "The", "But", "And", "Or", "An", "A"};
    std::map<std::string, std::string> authors = { {"Joyce", "James"},
        {"Austen", "Jane"},
        {"Dickens", "Charles"} };

    std::vector<int> ivec;
    for (std::vector<int>::size_type i = 0; i != 10; ++i) {
        ivec.push_back(i);
        ivec.push_back(i);
    }
    std::set<int> iset(ivec.cbegin(), ivec.cend());
    std::multiset<int> miset(ivec.cbegin(), ivec.cend());
    std::cout << ivec.size() << std::endl;
    std::cout << iset.size() << std::endl;
    std::cout << miset.size() << std::endl;

    std::multiset<Sales_data, decltype(compareIsbn) *>
        bookstore(compareIsbn);

    std::pair<std::string, std::string> anon;
    std::pair<std::string, size_t> word_count2;
    std::pair<std::string, std::vector<int>> line;
    std::pair<std::string, std::string> author{"James", "Joyce"};

    std::vector<std::string> svec;
    auto ret = process(svec);
    return 0;
}

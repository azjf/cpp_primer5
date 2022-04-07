#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include <numeric>

#include "Sales_data.h"

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

struct matches
{
    matches(std::vector<Sales_data>::size_type id,
    std::vector<Sales_data>::const_iterator beg,
    std::vector<Sales_data>::const_iterator end)
        : id(id), beg(beg), end(end) {}

    std::vector<Sales_data>::size_type id;
    std::vector<Sales_data>::const_iterator beg;
    std::vector<Sales_data>::const_iterator end;
};

std::vector<matches>
findBook(const std::vector<std::vector<Sales_data>> &files,
        const std::string &book)
{
    std::vector<matches> ret;
    for (auto it = files.begin(); it != files.cend(); ++it) {
        auto found = std::equal_range(it->cbegin(), it->cend(), book,
                compareIsbn);
        if (found.first != found.second) {
            ret.push_back(matches(it - files.cbegin(), found.first,
                        found.second));
        }
    }
    return ret;
}

void reportResults(std::istream &in, std::ostream &os,
        const std::vector<std::vector<Sales_data>> &files)
{
    std::string s;
    while (in >> s) {
        auto trans = findBook(files, s);
        if (trans.empty()) {
            std::cout << s << " not found in any stores" << std::endl;
            continue;
        }
        for (const auto &store : trans) {
            os << "store " << store.id << " sales: "
                << std::accumulate(store.beg, store.end, Sales_data(s))
                << std::endl;
        }
    }
}

int main()
{
    std::vector<Sales_data> store;
    std::ifstream ifs("trans");
    Sales_data trans;
    while (ifs >> trans) {
        store.push_back(trans);
    }

    std::vector<std::vector<Sales_data>> files{store, store};
    reportResults(std::cin, std::cout, files);
    return 0;
}

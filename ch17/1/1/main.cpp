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

typedef std::tuple<std::vector<Sales_data>::size_type,
        std::vector<Sales_data>::const_iterator,
        std::vector<Sales_data>::const_iterator> matches;

std::vector<matches>
findBook(const std::vector<std::vector<Sales_data>> &files,
        const std::string &book)
{
    std::vector<matches> ret;
    for (auto it = files.begin(); it != files.cend(); ++it) {
        auto found = std::equal_range(it->cbegin(), it->cend(), book,
                compareIsbn);
        if (found.first != found.second) {
            ret.push_back(std::make_tuple(it - files.cbegin(),
                        found.first, found.second));
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
            os << "store " << std::get<0>(store) << " sales: "
                << std::accumulate(std::get<1>(store), std::get<2>(store),
                        Sales_data(s))
                << std::endl;
        }
    }
}

int main()
{
    {
    std::tuple<std::size_t, std::size_t, std::size_t> threeD;
    std::tuple<std::string, std::vector<double>, int, std::list<int>>
        someVal("constants", {3.14, 2.718}, 42, {0, 1, 2, 3, 4, 5});
    std::tuple<std::size_t, std::size_t, std::size_t> threeD21 = {1, 2, 3};
    std::tuple<std::size_t, std::size_t, std::size_t> threeD22{1, 2, 3};
    auto item = std::make_tuple("0-999-78345-X", 3, 20.00);

    typedef decltype(item) trans;
    size_t sz = std::tuple_size<trans>::value;
    std::tuple_element<1, trans>::type cnt = std::get<1>(item);

    std::tuple<std::string, std::string> duo("1", "2");
    std::tuple<size_t, size_t> twoD(1, 2);
    //bool b = (duo == twoD);
    threeD = {1, 2, 3};
    //bool b = (twoD < threeD);
    std::tuple<size_t, size_t> origin(0, 0);
    bool b = (origin < twoD);
    }

    {
    std::vector<Sales_data> store;
    std::ifstream ifs("trans");
    Sales_data trans;
    while (ifs >> trans) {
        store.push_back(trans);
    }

    std::vector<std::vector<Sales_data>> files{store, store};
    reportResults(std::cin, std::cout, files);
    }
    return 0;
}

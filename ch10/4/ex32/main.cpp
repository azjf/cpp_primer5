#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <numeric>
#include "Sales_item.h"

int main()
{
    std::istream_iterator<Sales_item> in_it(std::cin), eof;
    std::ostream_iterator<Sales_item> out_it(std::cout, "\n");

    std::vector<Sales_item> svec;
    std::copy(in_it, eof, std::back_inserter(svec));

    auto compareIsbn = [] (const Sales_item &s1, const Sales_item &s2)
    { return s1.isbn() < s2.isbn(); };
    std::sort(svec.begin(), svec.end(), compareIsbn);
    std::copy(svec.cbegin(), svec.cend(), out_it);

    auto it = svec.cbegin();
    while (it != svec.cend()) {
        auto cur_end = std::find_if(it, svec.cend(),
                [it] (const Sales_item &s) { return s.isbn() != it->isbn(); });
        //auto cur_end = std::find(it, svec.cend(), *it);
        *out_it++ = std::accumulate(it, cur_end, Sales_item(it->isbn()));
        it = cur_end;
    }
    return 0;
}

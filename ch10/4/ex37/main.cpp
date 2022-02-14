#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

int main()
{
    std::vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto b = ivec.crbegin() + 4, e = ivec.crbegin() + 7;
    std::list<int> ilst;
    std::copy(b, e, std::back_inserter(ilst));
    for (const auto &i : ilst) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    ilst.erase(ilst.begin(), ilst.end());
    std::copy(ivec.cbegin() + 3, ivec.cbegin() + 6, std::front_inserter(ilst));
    for (const auto &i : ilst) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}

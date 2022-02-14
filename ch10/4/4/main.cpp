#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto r_iter = vec.crbegin();
            r_iter != vec.crend();
            ++r_iter) {
        std::cout << *r_iter << std::endl;
    }

    std::sort(vec.begin(), vec.end());
    std::sort(vec.rbegin(), vec.rend());

    std::string line("FIRST,MIDDLE,LAST");
    auto comma = std::find(line.cbegin(), line.cend(), ',');
    std::cout << std::string(line.cbegin(), comma) << std::endl;

    auto rcomma = std::find(line.crbegin(), line.crend(), ',');
    std::cout << std::string(line.crbegin(), rcomma) << std::endl;
    std::cout << std::string(rcomma.base(), line.cend()) << std::endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    std::vector<int> ivec{1, 2, 3, 4};
    auto it = --ivec.cend();
    while (it != ivec.cbegin()) {
        std::cout << *it-- << " ";
    }
    std::cout << *it << std::endl;
    return 0;
}

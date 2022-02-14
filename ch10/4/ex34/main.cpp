#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    std::vector<int> ivec{1, 2, 3, 4};
    auto it = ivec.crbegin();
    while (it != ivec.crend()) {
        std::cout << *it++ << " ";
    }
    std::cout << std::endl;

    std::ostream_iterator<int> out_it(std::cout, " ");
    std::copy(ivec.crbegin(), ivec.crend(), out_it);
    std::cout << std::endl;
    return 0;
}

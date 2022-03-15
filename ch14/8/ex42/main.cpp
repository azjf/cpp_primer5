#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
    std::vector<int> ivec{1, 2, 1024, 1025, 1026};
    std::cout << std::count_if(ivec.cbegin(), ivec.cend(),
            std::bind(std::greater<int>(), std::placeholders::_1, 1024))
        << std::endl;

    std::vector<std::string> svec{"pooh", "pooh", "pooi"};
    std::cout << *std::find_if(svec.cbegin(), svec.cend(),
            std::bind(std::not_equal_to<std::string>(), std::placeholders::_1,
                "pooh"))
        << std::endl;

    std::for_each(ivec.begin(), ivec.end(),
            [](int &n) { n = std::multiplies<int>()(n, 2); });
    std::for_each(ivec.cbegin(), ivec.cend(),
            [] (int n) { std::cout << n << " "; });
    std::cout << std::endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
    std::vector<int> ivec{2, 4, 6, 8};
    auto it = std::find_if(ivec.cbegin(), ivec.cend(),
            std::bind(std::modulus<int>(), std::placeholders::_1, 2));
    std::cout << (it == ivec.cend() ? "true" : "false") << std::endl;
    return 0;
}

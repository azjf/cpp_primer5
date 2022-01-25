#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ivec1{0, 1, 1, 2};
    std::vector<int> ivec2{0, 1, 1, 2, 3, 5, 8};

    decltype(ivec1.size()) i = 0;
    for (; i != ivec1.size() && i != ivec2.size()
            && ivec1[i] == ivec2[i]; ++i);
    std::cout << (i == ivec1.size() || i == ivec2.size()
            ? "true" : "false") << std::endl;
    return 0;
}

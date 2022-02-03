#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ivec1{1, 2, 3}, ivec2{1, 2, 3};
    bool res1 = ivec1 == ivec2;

    bool res2 = true;
    auto it1 = ivec1.cbegin(), it2 = ivec2.cbegin();
    while (it1 != ivec1.cend() && it2 != ivec2.cend()) {
        if (*it1 != *it2) {
            res2 = false;
            break;
        }
        ++it1;
        ++it2;
    }
    if (it1 != ivec1.cend() || it2 != ivec2.cend()) {
        res2 = false;
    }

    std::cout << (res1 ? "true" : "false") << std::endl;
    std::cout << (res2 ? "true" : "false") << std::endl;
    return 0;
}

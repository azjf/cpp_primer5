#include <iostream>
#include <list>
#include <vector>

int main()
{
    std::vector<int> ivec{1, 2, 3};
    std::list<int> ilist{1, 2, 3};

    bool res = true;
    auto it1 = ivec.cbegin();
    auto it2 = ilist.cbegin();
    while (it1 != ivec.cend() && it2 != ilist.cend()) {
        if (*it1 != *it2) {
            res = false;
            break;
        }
        ++it1;
        ++it2;
    }
    if (it1 != ivec.cend() || it2 != ilist.cend()) {
        res = false;
    }

    std::cout << (res ? "true" : "false") << std::endl;
    return 0;
}

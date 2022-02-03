#include <iostream>
#include <vector>
#include <list>

int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    std::vector<int> ivec(std::begin(ia), std::end(ia));
    std::list<int> ilist(std::begin(ia), std::end(ia));

    auto it = ivec.cbegin();
    while (it != ivec.cend()) {
        if (*it % 2 == 0) {
            it = ivec.erase(it);
        } else {
            ++it;
        }
    }

    auto it2 = ilist.begin();
    while (it2 != ilist.end()) {
        if (*it2 % 2) {
            it2 = ilist.erase(it2);
        } else {
            ++it2;
        }
    }
    return 0;
}

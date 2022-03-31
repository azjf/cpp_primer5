#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <algorithm>

template<typename I, typename V>
I find2(I beg, I end, const V &v)
{
    while (beg != end && *beg != v) {
        ++beg;
    }
    return beg;
}

int main()
{
    std::vector<int> ivec{1, 2, 3};
    std::cout << *find2(ivec.cbegin(), ivec.cend(), 1) << std::endl;

    std::list<std::string> slist{"hello", "world"};
    std::cout << *find2(slist.cbegin(), slist.cend(), "hello") << std::endl;
    return 0;
}

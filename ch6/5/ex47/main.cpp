#include <iostream>
#include <vector>
#include <cassert>

void print(std::vector<int>::const_iterator beg,
        std::vector<int>::const_iterator end)
{
#ifndef NDEBUG
    std::cout << "vector size: " << end - beg << std::endl;
#endif
    if (beg == end) {
#ifdef NDEBUG
    std::cout << std::endl;
#endif
        return;
    }
#ifndef NDEBUG
    std::cout << *beg++ << std::endl;
#else
    std::cout << *beg++ << " ";
#endif
    print(beg, end);
}

int main()
{
    const std::vector<int> ivec{1, 2, 3, 4, 5};
    print(ivec.cbegin(), ivec.cend());
    return 0;
}

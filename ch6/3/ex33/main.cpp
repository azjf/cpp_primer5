#include <iostream>
#include <vector>

void print(std::vector<int>::const_iterator beg,
        std::vector<int>::const_iterator end)
{
    if (beg == end) {
        std::cout << std::endl;
        return;
    }
    std::cout << *beg++ << " ";
    print(beg, end);
}

int main()
{
    const std::vector<int> ivec{1, 2, 3, 4, 5};
    print(ivec.cbegin(), ivec.cend());
    return 0;
}

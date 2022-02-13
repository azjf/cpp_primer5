#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> ivec{1, 2, 3, 4};
    std::fill_n(ivec.begin(), ivec.size(), 0);
    return 0;
}

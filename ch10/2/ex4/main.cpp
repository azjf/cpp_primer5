#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

int main()
{
    std::vector<double> ivec{1, 2, 3, 4};
    std::cout << std::accumulate(ivec.cbegin(), ivec.cend(), 0)
        << std::endl;
    return 0;
}

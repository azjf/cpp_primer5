#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ivec1;
    std::vector<int> ivec2(10);
    std::vector<int> ivec3(10, 0);
    std::vector<int> ivec41{1, 2, 3, 4};
    std::vector<int> ivec42 = {1, 2, 3, 4};
    std::vector<int> ivec51(ivec3);
    std::vector<int> ivec52 = ivec3;
    std::vector<int> ivec6(ivec3.cbegin(), ivec3.cend());
    return 0;
}

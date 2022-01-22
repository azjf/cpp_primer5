#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ivec{0, 1, 2, 3, 4, 5, 7, 8, 9};
    for (auto it = ivec.begin(); it != ivec.end(); ++it) {
        *it *= *it;
    }
    for (auto it = ivec.cbegin(); it != ivec.cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}

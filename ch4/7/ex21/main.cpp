#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ivec{1, 2, 3, 4, 5};
    for (auto &n : ivec) {
        n = n % 2 == 0 ? n : n * 2;
    }

    for (const auto &n : ivec) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    return 0;
}

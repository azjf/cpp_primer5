#include <iostream>
#include <vector>

int main()
{
    const int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };

    for (auto &arr : ia) {
        for (const int &n : arr) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    for (size_t i = 0; i != 3; ++i) {
        for (size_t j = 0; j != 4; ++j) {
            std::cout << ia[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    for (auto p = ia; p != std::end(ia); ++p) {
        for (auto q = *p; q != *p + 4; ++q) {
            std::cout << *q << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

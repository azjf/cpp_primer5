#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ivec;
    int num;
    while (std::cin >> num) {
        ivec.push_back(num);
    }

    for (auto it = ivec.cbegin(); it + 1 <= ivec.cend(); it += 2) {
        std::cout << *it + *(it + 1) << " ";
    }
    std::cout << std::endl;

    for (auto l = ivec.cbegin(), r = ivec.cend() - 1; l < r; ++l, --r) {
        std::cout << *l + *r << " ";
    }
    std::cout << std::endl;
    return 0;
}

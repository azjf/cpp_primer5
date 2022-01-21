#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ivec;
    int n;
    while (std::cin >> n) {
        ivec.push_back(n);
    }

    for (decltype(ivec.size()) i = 0; i + 1 < ivec.size(); i += 2) {
        std::cout << ivec[i] + ivec[i + 1] << " ";
    }
    std::cout << std::endl;

    decltype(ivec.size()) i = 0, j = ivec.size() - 1;
    while (i < j) {
        std::cout << ivec[i++] + ivec[j--] << " ";
    }
    std::cout << std::endl;
    return 0;
}

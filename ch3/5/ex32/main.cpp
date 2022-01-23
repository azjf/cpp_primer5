#include <iostream>
#include <vector>

int main()
{
    int arr[10];
    for (size_t i = 0; i != 10; ++i) {
        arr[i] = i;
    }

    int arr2[10];
    for (size_t i = 0; i != 10; ++i) {
        arr2[i] = arr[i];
    }

    for (auto &n : arr2) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    std::vector<int> ivec;
    for (int i = 0; i != 10; ++i) {
        ivec.push_back(i);
    }
    for (auto &n : ivec) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    return 0;
}

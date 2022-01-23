#include <iostream>

int main()
{
    int arr[10];
    for (size_t i = 0; i < 10; ++i) {
        arr[i] = i;
    }

    for (auto &n : arr) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    return 0;
}

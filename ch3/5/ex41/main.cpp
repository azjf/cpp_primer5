#include <iostream>
#include <vector>

int main()
{
    int arr[5]{1, 2, 3, 4};
    std::vector<int> ivec(std::cbegin(arr), std::cend(arr));
    std::vector<int> ivec2(arr, std::end(arr));
    return 0;
}

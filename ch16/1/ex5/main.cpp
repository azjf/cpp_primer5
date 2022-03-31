#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <algorithm>

template <typename T, unsigned N>
void print(T (&arr)[N])
{
    for (const auto &elem : arr) {
        std::cout << elem << std::endl;
    }
}

int main()
{
    int iarr[]{1, 2, 3};
    print(iarr);

    std::string sarr[]{"hello", "world"};
    print(sarr);
    return 0;
}

#include <iostream>
#include <memory>
#include <vector>
#include <list>

template <typename T, unsigned N>
constexpr unsigned arr_size(T (&arr)[N])
{
    return N;
}

int main()
{
    int iarr[]{1, 2, 3};
    std::cout << arr_size(iarr) << std::endl;
    return 0;
}

#include <iostream>
#include <memory>
#include <vector>
#include <list>

template <typename T, unsigned N>
T *begin_arr(T (&arr)[N])
{
    return arr;
}

template <typename T, unsigned N>
T *end_arr(T (&arr)[N])
{
    return arr + N;
}

int main()
{
    int iarr[]{1, 2, 3};
    std::cout << *begin_arr(iarr) << std::endl;
    std::cout << *(end_arr(iarr) - 1) << std::endl;
    return 0;
}

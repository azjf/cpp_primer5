#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <cstring>

template <typename It>
auto fcn(It beg, It end) -> decltype(*beg)
{
    return *beg;
}

template <typename It>
auto fcn3(It beg, It end) -> decltype(*beg + 0)
{
    return *beg;
}

int main()
{
    std::vector<int> ivec{1, 2, 3};
    int &i = fcn(ivec.begin(), ivec.end());
    std::cout << ++i << " " << ivec[0] << std::endl;
    //int &i2 = fcn3(ivec.begin(), ivec.end());
    return 0;
}

#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <cstring>

template <typename T>
auto sum(T lhs, T rhs) -> decltype(lhs + rhs)
{
    return lhs + rhs;
}

int main()
{
    std::cout << sum(static_cast<long long>(9e18),
            static_cast<long long>(9e18)) << std::endl;
    return 0;
}

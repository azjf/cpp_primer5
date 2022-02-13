#include <iostream>

int main()
{
    auto f = [] (int a, int b) { return a + b; };
    auto f2 = [] (int a, int b) -> int { return a + b; };
    std::cout << f(1, 2) << std::endl;
    std::cout << f2(1, 2) << std::endl;
    return 0;
}

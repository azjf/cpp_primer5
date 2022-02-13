#include <iostream>

int f(int a)
{
    auto ff = [a] (int b) { return a + b; };
    return ff(2);
}

int main()
{
    std::cout << f(1) << std::endl;
    return 0;
}

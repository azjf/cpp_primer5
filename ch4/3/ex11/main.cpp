#include <iostream>

int main()
{
    int a = -1, b = -2, c = -3, d = -4;
    std::cout << (a > b && b > c && c > d ? "true" : "false") << std::endl;
    return 0;
}

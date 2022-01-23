#include <iostream>
#include <vector>

int main()
{
    int x[10], *p = x;
    std::cout << sizeof(x) / sizeof(*x) << std::endl;
    std::cout << sizeof(p) / sizeof(*p) << std::endl;
    std::cout << "sizeof(p): " << sizeof(p) << std::endl;
    return 0;
}

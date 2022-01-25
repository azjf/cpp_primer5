#include <iostream>

int func() {
    static size_t cnt = -1;
    ++cnt;
    return cnt;
}

int main()
{
    std::cout << func() << std::endl;
    std::cout << func() << std::endl;
    return 0;
}

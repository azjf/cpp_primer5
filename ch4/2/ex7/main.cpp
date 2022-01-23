#include <iostream>

int main()
{

    char c = 127;
    ++c;
    std::cout << c << std::endl;

    c *= 3;
    std::cout << c << std::endl;

    c -= 1234;
    std::cout << c << std::endl;
    return 0;
}

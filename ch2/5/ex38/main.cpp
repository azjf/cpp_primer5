#include <iostream>

int main()
{
    int a = 1;
    const int b = 1;

    // same
    auto a1 = a;
    decltype(a) a2 = a;
    ++a1;
    ++a2;
    std::cout << a << " " << a1 << " " << a2 << std::endl;

    // different
    auto b1 = b;
    decltype(b) b2 = b;
    ++b1;
    //++b2;
    std::cout << b << " " << b1 << " " << b2 << std::endl;
    return 0;
}

#include <iostream>

int main()
{
    size_t sz = 6;
    char * const pa = new char[sz]();
    char c, *q = pa;
    while (std::cin >> c && q != pa + sz - 1) {
        *q++ = c;
    }
    std::cout << pa << std::endl;
    return 0;
}

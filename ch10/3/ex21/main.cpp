#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int n = 2;
    auto f = [n] () mutable { return n == 0 ? true : (--n, false); };
    std::cout << (f() ? "true" : "false") << std::endl;
    std::cout << (f() ? "true" : "false") << std::endl;
    std::cout << (f() ? "true" : "false") << std::endl;
    std::cout << (f() ? "true" : "false") << std::endl;
    return 0;
}

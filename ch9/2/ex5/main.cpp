#include <iostream>
#include <vector>

std::vector<int>::const_iterator f(std::vector<int>::const_iterator cbegin,
        std::vector<int>::const_iterator cend, int n)
{
    decltype(cbegin) ret = cend;
    while (cbegin != cend) {
        if (*cbegin == n) {
            ret = cbegin;
            break;
        }
        ++cbegin;
    }
    return ret;
}

int main()
{
    std::vector<int> ivec{1, 2, 3, 4, 5};
    auto it = f(ivec.cbegin(), ivec.cend(), 3);
    std::cout << (it != ivec.cend() ? "true" : "false") << std::endl;
    return 0;
}

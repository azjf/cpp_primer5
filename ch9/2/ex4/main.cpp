#include <iostream>
#include <vector>

bool f(std::vector<int>::const_iterator cbegin,
        std::vector<int>::const_iterator cend, int n)
{
    bool ret = false;
    while (cbegin != cend) {
        if (*cbegin == n) {
            ret = true;
            break;
        }
        ++cbegin;
    }
    return ret;
}

int main()
{
    std::vector<int> ivec{1, 2, 3, 4, 5};
    bool is_found = f(ivec.cbegin(), ivec.cend(), 3);
    std::cout << (is_found ? "true" : "false") << std::endl;
    return 0;
}

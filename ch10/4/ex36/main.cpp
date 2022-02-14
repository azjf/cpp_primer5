#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

int main()
{
    std::list<int> ilst{0, 1, 0, 1};
    auto it = std::find(ilst.crbegin(), ilst.crend(), 0);
    std::cout << (it != ilst.crend() ? "true" : "false") << std::endl;
    return 0;
}

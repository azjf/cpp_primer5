#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

int main()
{
    std::vector<int> ivec{1, 2, 3, 4};
    std::list<int> ilst;
    std::unique_copy(ivec.cbegin(), ivec.cend(),
            std::back_inserter(ilst));
    return 0;
}

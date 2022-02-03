#include <iostream>
#include <list>
#include <vector>

int main()
{
    std::list<int> ilst{1, 2, 3, 4};
    std::vector<double> dvec1(ilst.cbegin(), ilst.cend());

    std::vector<int> ivec{1, 2, 3, 4};
    std::vector<double> dvec2(ivec.cbegin(), ivec.cend());
    return 0;
}

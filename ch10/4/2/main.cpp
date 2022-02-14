#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <iterator>

int main()
{
    std::vector<int> vec{1, 2, 3, 4};
    std::ostream_iterator<int> out_iter(std::cout, " ");
    for (auto e : vec) {
        *out_iter++ = e;
    }
    std::cout << std::endl;
    for (auto e : vec) {
        out_iter = e;
    }
    std::cout << std::endl;

    std::copy(vec.begin(), vec.end(), out_iter);
    std::cout << std::endl;
    return 0;
}

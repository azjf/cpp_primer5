#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    std::istream_iterator<int> in_iter(std::cin), eof;
    std::vector<int> ivec;
    std::copy(in_iter, eof, std::back_inserter(ivec));

    std::sort(ivec.begin(), ivec.end());

    std::ostream_iterator<int> out_iter(std::cout, " ");
    std::copy(ivec.cbegin(), ivec.cend(), out_iter);
    std::cout << std::endl;
    return 0;
}

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

int main()
{
    std::istream_iterator<int> in_iter(std::cin), eof;
    std::vector<int> vec(in_iter, eof);
    return 0;
}

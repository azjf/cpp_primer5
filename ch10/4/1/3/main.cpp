#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <numeric>

int main()
{
    std::istream_iterator<int> in(std::cin), eof;
    std::cout << std::accumulate(in, eof, 0) << std::endl;
    return 0;
}

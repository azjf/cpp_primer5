#include <iostream>
#include <vector>
#include <iterator>

int main()
{
    std::istream_iterator<std::string> in_iter(std::cin), eof;
    std::vector<std::string> svec;
    std::copy(in_iter, eof, std::back_inserter(svec));

    std::ostream_iterator<std::string> out_iter(std::cout, " ");
    std::copy(svec.cbegin(), svec.cend(), out_iter);
    std::cout << std::endl;
    return 0;
}

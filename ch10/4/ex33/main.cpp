#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

int main(int argc, char *argv[])
{
    if (argc != 4) {
        return -1;
    }

    std::ifstream in(argv[1]);
    std::istream_iterator<int> in_it(in), eof;
    std::vector<int> ivec;
    std::copy(in_it, eof, std::back_inserter(ivec));

    std::ofstream out_odd(argv[2]), out_even(argv[3]);
    std::ostream_iterator<int> out_odd_it(out_odd, " "),
        out_even_it(out_even, " ");
    std::copy_if(ivec.cbegin(), ivec.cend(), out_odd_it,
            [] (int n) { return n % 2; });
    std::copy_if(ivec.cbegin(), ivec.cend(), out_even_it,
            [] (int n) { return n % 2 == 0; });
    return 0;
}

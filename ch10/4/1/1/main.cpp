#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <iterator>

int main()
{
    std::list<int> lst = {1, 2, 3, 4};
    std::list<int> lst2, lst3;
    std::copy(lst.cbegin(), lst.cend(), std::front_inserter(lst2));
    std::copy(lst.cbegin(), lst.cend(), std::inserter(lst3, lst3.begin()));

    std::istream_iterator<int> int_it(std::cin);
    std::istream_iterator<int> int_eof;
    std::ifstream in("afile");
    std::istream_iterator<std::string> str_it(in);

    std::istream_iterator<int> in_iter(std::cin);
    std::istream_iterator<int> eof;
    std::vector<int> vec;
    while (in_iter != eof) {
        vec.push_back(*in_iter++);
    }
    return 0;
}

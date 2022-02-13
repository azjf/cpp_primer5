#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

int main()
{
    std::string s("word");
    std::vector<int> ivec{1, 2, 3, 5, 6};
    
    auto check_size = [] (const std::string &s, std::string::size_type sz)
    { return s.size() <= sz; };
    std::cout << *std::find_if(ivec.cbegin(), ivec.cend(),
            std::bind(check_size, std::ref(s), std::placeholders::_1))
        << std::endl;
    return 0;
}

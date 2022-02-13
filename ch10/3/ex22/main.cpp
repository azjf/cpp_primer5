#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

int main()
{
    std::vector<std::string> words = {"the", "quick", "red", "fox",
        "jumps", "over", "the", "slow", "red", "turtle"};

    auto check_size = [] (const std::string &s, std::string::size_type sz)
    { return s.size() <= sz; };
    std::cout << std::count_if(words.cbegin(), words.cend(),
            std::bind(check_size, std::placeholders::_1, 6)) << std::endl;
    return 0;
}

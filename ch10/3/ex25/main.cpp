#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

void print(std::vector<std::string> &words)
{
    for (const auto &s : words) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

void biggies(std::vector<std::string> &words, std::string::size_type sz)
{
    std::sort(words.begin(), words.end());
    auto unique_end = std::unique(words.begin(), words.end());
    words.erase(unique_end, words.end());
    std::for_each(words.cbegin(), words.cend(),
            [] (const std::string &s) { std::cout << s << " "; });
    std::cout << std::endl;

    std::stable_sort(words.begin(), words.end(),
            [] (const std::string &s1, const std::string &s2)
            { return s1.size() < s2.size(); });
    std::for_each(words.cbegin(), words.cend(),
            [] (const std::string &s) { std::cout << s << " "; });
    std::cout << std::endl;

    auto check_size = [] (const std::string &s, std::string::size_type sz)
    { return s.size() < sz; };
    const auto it = std::partition(words.begin(), words.end(),
            std::bind(check_size, std::placeholders::_1, sz));
    std::cout << words.cend() - it << std::endl;
    std::for_each(it, words.end(),
            [] (const std::string &s) { std::cout << s << " "; });
    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> words = {"the", "quick", "red", "fox",
        "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(words, 5);
    return 0;
}

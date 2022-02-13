#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>
#include <iterator>

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

    const auto it = std::partition(words.begin(), words.end(),
            [sz] (const std::string &s) { return s.size() < sz; });
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

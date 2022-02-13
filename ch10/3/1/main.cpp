#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>
#include <iterator>

bool isShorter(const std::string &s1, const std::string &s2)
{
    return s1.size() < s2.size();
}

void print(std::vector<std::string> &words)
{
    for (const auto word : words) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
}

void elimDups(std::vector<std::string> &words)
{
    std::sort(words.begin(), words.end());
    print(words);
    auto unique_end = std::unique(words.begin(), words.end());
    print(words);
    words.erase(unique_end, words.end());
    print(words);
}

int main()
{
    std::vector<std::string> words{"hello", "world", "hi"};
    std::sort(words.begin(), words.end(), isShorter);

    words = {"the", "quick", "red", "fox",
        "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(words);
    std::stable_sort(words.begin(), words.end(), isShorter);
    for (const auto &s : words) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
    return 0;
}

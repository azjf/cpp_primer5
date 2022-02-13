#include <iostream>
#include <algorithm>
#include <vector>

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

bool isShorter(const std::string &s1, const std::string &s2)
{
    return s1.size() < s2.size();
}

int main()
{
    std::vector<std::string> words{"the", "quick", "red", "fox",
        "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(words);
    std::stable_sort(words.begin(), words.end(), isShorter);
    print(words);
    return 0;
}

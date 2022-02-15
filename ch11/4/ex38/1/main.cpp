#include <iostream>
#include <unordered_map>
#include <set>

int main()
{
    std::unordered_map<std::string, size_t> word_count;
    std::set<std::string> exclude = {"The", "But", "And", "Or", "An", "A",
        "the", "but", "and", "or", "an", "a"};
    std::string word;
    while (std::cin >> word) {
        if (exclude.find(word) == exclude.end()) {
            ++word_count[word];
        }
    }
    for (const auto &w : word_count) {
        std::cout << w.first << " occurs " << w.second
            << ((w.second > 1) ? " times" : " time") << std::endl;
    }
    return 0;
}

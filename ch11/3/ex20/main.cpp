#include <iostream>
#include <map>
#include <set>

int main()
{
    std::map<std::string, size_t> word_count;
    std::string word;
    while (std::cin >> word) {
        //++word_count[word];
        auto ret = word_count.insert({word, 1});
        if (!ret.second) {
            ++ret.first->second;
        }
    }
    for (const auto &p : word_count) {
        std::cout << p.first << ": " << p.second << std::endl;
    }
    return 0;
}

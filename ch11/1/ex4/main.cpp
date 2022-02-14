#include <iostream>
#include <map>
#include <set>
#include <algorithm>

int main()
{
    std::map<std::string, size_t> word_count;
    std::string word;
    while (std::cin >> word) {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());
        ++word_count[word];
    }
    for (const auto &p : word_count) {
        std::cout << p.first << ": " << p.second << std::endl;
    }
    return 0;
}

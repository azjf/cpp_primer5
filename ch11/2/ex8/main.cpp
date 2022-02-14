#include <iostream>
#include <vector>
#include <set>

int main()
{
    std::vector<std::string> words{"hello", "world", "world"};
    std::vector<std::string> uniq_words;
    for (const auto &w : words) {
        bool is_exist = false;
        for (const auto &uw : uniq_words) {
            if (uw == w) {
                is_exist = true;
                break;
            }
        }
        if (!is_exist) {
            uniq_words.push_back(w);
        }
    }
    std::cout << uniq_words.size() << std::endl;
    
    std::set<std::string> uniq_word_set(words.cbegin(), words.cend());
    std::cout << uniq_word_set.size() << std::endl;
    return 0;
}

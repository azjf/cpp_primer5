#include <iostream>
#include <fstream>
#include <sstream>
#include <map>


void word_transform(std::ifstream &ifs_text, std::ifstream &ifs_rule);

int main()
{
    std::ifstream ifs_text("text"), ifs_rule("rule");
    word_transform(ifs_text, ifs_rule);
    return 0;
}

std::map<std::string, std::string> build_trans_map(std::ifstream &ifs_rule)
{
    std::map<std::string, std::string> trans_map;
    std::string key, value;
    while (ifs_rule >> key && std::getline(ifs_rule, value)) {
        if (value.size() <= 1) {
            break;
        }
        trans_map[key] = value.substr(1);
    }
    return trans_map;
}

const std::string &transform(const std::string &word,
        const std::map<std::string, std::string> &trans_map)
{
    auto map_it = trans_map.find(word);
    if (map_it == trans_map.cend()) {
        return word;
    } else {
        return map_it->second;
    }
}

void word_transform(std::ifstream &ifs_text, std::ifstream &ifs_rule)
{
    std::map<std::string, std::string> trans_map = build_trans_map(ifs_rule);
    std::string line;
    while (std::getline(ifs_text, line)) {
        std::stringstream ss(line);
        std::string word;
        bool is_first_word = true;
        while (ss >> word) {
            if (is_first_word) {
                is_first_word = false;
            } else {
                std::cout << " ";
            }
            std::cout << transform(word, trans_map);
        }
        std::cout << std::endl;
    }
}

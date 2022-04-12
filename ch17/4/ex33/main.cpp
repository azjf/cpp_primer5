#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <random>

std::map<std::string, std::string> buildMap(std::ifstream &map_file)
{
    std::map<std::string, std::string> trans_map;
    std::string key;
    std::string value;
    while (map_file >> key && std::getline(map_file, value)) {
        if (value.size() > 1) {
            trans_map[key] = value.substr(1);
        } else {
            throw std::runtime_error("no rule for " + key);
        }
    }
    return trans_map;
}

const std::string &transform(
        const std::string &s,
        const std::map<std::string, std::string> &m)
{
    std::cout << "transform1() ";
    auto map_it = m.find(s);
    if (map_it != m.cend()) {
        return map_it->second;
    } else {
        return s;
    }
}

const std::string &transform2(
        const std::string &s,
        const std::map<std::string, std::string> &m)
{
    std::cout << "transform2() ";
    auto map_it = m.find(s);
    if (map_it != m.cend()) {
        return map_it->second;
    } else {
        return s;
    }
}

const std::string &transform3(
        const std::string &s,
        const std::map<std::string, std::string> &m)
{
    std::cout << "transform3() ";
    auto map_it = m.find(s);
    if (map_it != m.cend()) {
        return map_it->second;
    } else {
        return s;
    }
}

void word_transform(std::ifstream &map_file, std::ifstream &input)
{
    auto trans_map = buildMap(map_file);
    std::string text;

    const std::string &(*transform_funcs[3])
        (const std::string &, const std::map<std::string, std::string> &)
        { transform, transform2, transform3 };
    static std::default_random_engine e;
    static std::uniform_int_distribution<> u(0, 2);

    while (std::getline(input, text)) {
        std::istringstream stream(text);
        std::string word;
        bool firstword = true;
        while (stream >> word) {
            if (firstword) {
                firstword = false;
            } else {
                std::cout << " ";
            }
            std::cout << transform_funcs[u(e)](word, trans_map);
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::ifstream ifs_rule("rule");
    std::ifstream ifs_text("text");
    word_transform(ifs_rule, ifs_text);
    return 0;
}

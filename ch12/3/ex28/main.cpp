#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <memory>

void runQueries(std::ifstream &infile)
{
    auto text_sp = std::make_shared<std::vector<std::string>>();
    auto word_map_sp = std::make_shared<std::map<std::string, std::set<size_t>>>();
    std::string line;
    while (std::getline(infile, line)) {
        text_sp->push_back(line);
        std::stringstream ss(line);
        std::string word;
        while (ss >> word) {
            (*word_map_sp)[word].insert(text_sp->size());
        }
    }

    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") {
            break;
        }
        auto map_it = (*word_map_sp).find(s);
        if (map_it == (*word_map_sp).cend()) {
            std::cout << s << " not found";
        }
        const auto line_nums = map_it->second;
        std::cout << s << " occurs " << line_nums.size() << " time(s)\n";
        for (const auto &n : line_nums) {
            std::cout << "\t(line " << n << ") " << (*text_sp)[n - 1] << "\n";
        }
    }
}

int main()
{
    std::ifstream ifs("text");
    runQueries(ifs);
    return 0;
}

#include <iostream>
#include <vector>
#include <map>

int main()
{
    std::multimap<std::string, std::string> authors{
        {"hello2", "world1"},
        {"hello", "world2"},
        {"hi", "world1"} };
    for (auto beg = authors.cbegin(); beg != authors.cend(); ++beg) {
        std::cout << beg->first << " " << beg->second << std::endl;
    }

    for (const auto &p : authors) {
        std::cout << p.first << " " << p.second << std::endl;
    }
    return 0;
}

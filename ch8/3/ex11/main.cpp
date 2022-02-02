#include <iostream>
#include <sstream>
#include <vector>
#include "PersonInfo.h"

int main()
{
    std::string line, word;
    std::vector<PersonInfo> people;
    std::istringstream record;
    while (std::getline(std::cin, line)) {
        record.clear();
        record.str(line);
        PersonInfo info;
        record >> info.name;
        std::cout << info.name << " ";
        while (record >> word) {
            info.phones.push_back(word);
            std::cout << word << " ";
        }
        std::cout << std::endl;
        people.push_back(info);
    }
    return 0;
}

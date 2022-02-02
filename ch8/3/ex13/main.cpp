#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "PersonInfo.h"

bool valid(std::string nums) { return true; }
std::string format(std::string nums) { return nums; }

int main()
{
    std::ifstream input("infile");
    if (!input) {
        return -1;
    }

    std::string line, word;
    std::vector<PersonInfo> people;
    while (std::getline(input, line)) {
        PersonInfo info;
        std::istringstream record(line);
        record >> info.name;
        while (record >> word) {
            info.phones.push_back(word);
        }
        people.push_back(info);
    }

    for (const auto &entry : people) {
        std::ostringstream formatted, badNums;
        for (const auto &nums : entry.phones) {
            if (!valid(nums)) {
                badNums << " " << nums;
            } else {
                formatted << " " << format(nums);
            }
        }
        if (badNums.str().empty()) {
            //os << entry.name << " "
            std::cout << entry.name << " "
                << formatted.str() << std::endl;
        } else {
            std::cerr << "input error: " << entry.name
                << " invalid number(s) " << badNums.str() << std::endl;
        }
    }
    return 0;
}

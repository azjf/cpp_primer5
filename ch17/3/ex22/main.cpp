#include <iostream>
#include <sstream>
#include <vector>
#include <regex>
#include "PersonInfo.h"

bool valid(const std::string &nums)
{
    std::string phone = "(\\()?(\\d{3})(\\))?([-.]| +)?(\\d{3})([-.]| +)(\\d{4})";
    std::regex r(phone);
    std::smatch m;
    if (!std::regex_match(nums, m, r)) {
        return false;
    }
    if (m[1].matched) {
        return m[3].matched && (m[4].matched == 0
                || std::regex_match(m[4].str(), std::regex(" +")));
    } else {
        if (m[3].matched) {
            return false;
        }

        std::regex rr(" +");
        if (!std::regex_match(m[4].str(), rr)) {
            return m[4].str() == m[6].str();
        } else {
            return std::regex_match(m[6].str(), rr);
        }
    }
}

std::string format(std::string nums) { return nums; }

int main()
{
    std::string line, word;
    std::vector<PersonInfo> people;
    while (std::getline(std::cin, line)) {
        PersonInfo info;
        std::istringstream record(line);
        std::getline(record, info.name, ',');
        while (std::getline(record, word, ',')) {
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

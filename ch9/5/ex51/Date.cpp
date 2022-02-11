#include <vector>
#include "Date.h"

unsigned s2month(std::string s)
{
    std::vector<std::string> months{"January", "Februray", "March",
        "April", "May", "June", "July", "August", "September",
        "November", "December"};
    size_t res = -1;
    for (size_t i = 0; i != months.size(); ++i) {
        if (months[i].find(s) != std::string::npos) {
            res = i + 1;
            break;
        }
    }
    return res;
}

Date::Date(std::string s) : Date()
{
    std::string sy, sm, sd;
    if (s.find(',') != std::string::npos) {
        auto pos1 = s.find(' '), pos2 = s.find(',');
        if (pos1 == std::string::npos || pos2 == std::string::npos) {
            return;
        }
        year = std::stoul(s.substr(pos2 + 2));
        month = s2month(s.substr(0, pos1));
        day = std::stoul(s.substr(pos1 + 1, pos2 - pos1 - 1));
    } else if (s.find('/') != std::string::npos) {
        auto pos1 = s.find('/'), pos2 = s.find('/', pos1 + 1);
        if (pos1 == std::string::npos || pos2 == std::string::npos) {
            return;
        }
        year = std::stoul(s.substr(pos2 + 1));
        month = std::stoul(s.substr(0, pos1));
        day = std::stoul(s.substr(pos1 + 1, pos2 - pos1 - 1));
    } else {
        auto pos1 = s.find(' '), pos2 = s.find(' ', pos1 + 1);
        if (pos1 == std::string::npos || pos2 == std::string::npos) {
            return;
        }
        year = std::stoul(s.substr(pos2 + 1));
        month = s2month(s.substr(0, pos1));
        day = std::stoul(s.substr(pos1 + 1, pos2 - pos1 - 1));
    }
}

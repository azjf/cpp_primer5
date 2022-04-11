#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <regex>

int main()
{
    std::string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])(\\d{4})";
    std::regex r(phone);
    std::smatch m;
    std::string s;
    std::string fmt = "$2.$5.$7";
    while (getline(std::cin, s)) {
        std::cout << std::regex_replace(s, r, fmt) << std::endl;
    }
    return 0;
}

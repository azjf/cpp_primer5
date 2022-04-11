#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <regex>

int main()
{
    {
    std::string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])(\\d{4})";
    std::string fmt = "$2.$5.$7";
    std::regex r(phone);
    std::string number = "(908) 555-1800";
    std::cout << std::regex_replace(number, r, fmt) << std::endl;
    }

    {
    std::string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])(\\d{4})";
    std::regex r(phone);
    std::smatch m;
    std::string s;
    std::string fmt = "$2.$5.$7";
    while (getline(std::cin, s)) {
        std::cout << std::regex_replace(s, r, fmt) << std::endl;

        using std::regex_constants::format_no_copy;
        using namespace std::regex_constants;
        std::cout << std::regex_replace(s, r, fmt, format_no_copy) << std::endl;
    }
    }
    return 0;
}

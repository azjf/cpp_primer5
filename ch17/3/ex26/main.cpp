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
        std::sregex_iterator it(s.cbegin(), s.cend(), r), end_it;
        if (it == end_it) {
            continue;
        }
        std::string first_match = it->format(fmt);
        std::cout << it->prefix();

        std::size_t cnt = 0;
        while (++it != end_it) {
            std::cout << it->format(fmt) << " ";
            ++cnt;
        }
        if (!cnt) {
            std::cout << first_match << std::endl;
        } else {
            std::cout << std::endl;
        }
    }
    return 0;
}

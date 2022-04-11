#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <regex>

int main()
{
    std::regex r("\\d{5}-?\\d{4}");
    std::smatch m;
    std::string s("12345-6789");
    if (std::regex_match(s, m, r)) {
        std::cout << m.str() << std::endl;
    }
    return 0;
}

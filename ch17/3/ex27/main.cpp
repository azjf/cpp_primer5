#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <regex>

int main()
{
    std::regex r("(\\d{5})-?(\\d{4})");
    std::smatch m;
    std::string s("123456789");
    std::cout << std::regex_replace(s, r, "$1-$2") << std::endl;
    return 0;
}

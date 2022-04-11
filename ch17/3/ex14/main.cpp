#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <regex>

int main()
{
    // error_brack
    try {
        std::regex r("[", std::regex::icase);
    } catch (std::regex_error &e) {
        std::cout << e.what() << "\ncode: " << e.code() << std::endl;
    }
    // error_paren
    try {
        std::regex r("(", std::regex::icase);
    } catch (std::regex_error &e) {
        std::cout << e.what() << "\ncode: " << e.code() << std::endl;
    }
    // error_range
    try {
        std::regex r("[z-a]", std::regex::icase);
    } catch (std::regex_error &e) {
        std::cout << e.what() << "\ncode: " << e.code() << std::endl;
    }
    return 0;
}

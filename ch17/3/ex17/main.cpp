#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <regex>

int main()
{
    std::string pattern("[^c]ei");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    std::regex r(pattern);
    std::smatch results;
    std::string file = "receipt freind theif receive";
    for (std::sregex_iterator it(file.begin(), file.end(), r), end_it;
            it != end_it; ++it) {
        std::cout << it->str() << std::endl;
    }
    return 0;
}

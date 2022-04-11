#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <regex>

int main()
{
    {
    std::string pattern("[^c]ei");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    std::regex r(pattern);
    std::smatch results;
    std::string test_str = "receipt freind theif receive";
    if (std::regex_search(test_str, results, r)) {
        std::cout << results.str() << std::endl;
    }
    }

    {
    //std::regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$", std::regex::icase);
    std::regex r("([[:alnum:]]+)\\.(cpp|cxx|cc)$", std::regex::icase);
    std::smatch results;
    std::string filename;
    while (std::cin >> filename) {
        if (std::regex_search(filename, results, r)) {
            std::cout << results.str() << std::endl;
            std::cout << results.str(1) << std::endl;
        }
    }
    }

    {
    try {
        std::regex r("[[:alnum:]+\\.(cpp|cxx|cc)$", std::regex::icase);
    } catch (std::regex_error &e) {
        std::cout << e.what() << "\ncode: " << e.code() << std::endl;
    }

    std::regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$", std::regex::icase);
    //std::smatch results;
    std::cmatch results;
    if (std::regex_search("myfile.cc", results, r)) {
        std::cout << results.str() << std::endl;
    }
    }

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
    for (std::sregex_iterator it(file.begin(), file.end(), r), end_it;
            it != end_it; ++it) {
        auto pos = it->prefix().length();
        pos = pos > 40 ? pos - 40 : 0;
        std::cout << it->prefix().str().substr(pos)
            << "\n\t\t>>> " << it->str() << " <<<\n"
            << it->suffix().str().substr(0, 40)
            << std::endl;
    }
    }
    return 0;
}

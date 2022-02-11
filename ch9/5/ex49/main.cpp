#include <iostream>

int main()
{
    std::string ascender("bdfhijklt"), descender("gjpqy");
    std::string chs(ascender + descender);
    std::string res, word;
    while (std::cin >> word) {
        if (word.find_first_of(chs) == std::string::npos
                && word.size() > res.size()) {
            res = word;
        }
    }
    std::cout << res << std::endl;
    return 0;
}

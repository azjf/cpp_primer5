#include <iostream>
#include <vector>

int main()
{
    std::string s("some string");
    if (s.begin() != s.end()) {
        auto it = s.begin();
        *it = std::toupper(*it);
    }
    std::cout << s << std::endl;

    s = "some string";
    for (auto it = s.begin(); it != s.end() && !std::isspace(*it); ++it) {
        *it = std::toupper(*it);
    }
    std::cout << s << std::endl;

    std::vector<std::string> text{"hello", "world", "", "hi"};
    for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it) {
        std::cout << *it << std::endl;
    }
    return 0;
}

#include <iostream>
#include <vector>

int main()
{
    std::vector<std::string> text{"hello", "world", "", "hi"};
    for (auto it = text.begin(); it != text.end() && !it->empty(); ++it) {
        for (auto &c : *it) {
            c = std::toupper(c);
        }
    }
    for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it) {
        std::cout << *it << std::endl;
    }
    return 0;
}

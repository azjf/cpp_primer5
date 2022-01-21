#include <iostream>

int main()
{
    std::string s;
    if (!std::getline(std::cin, s)) {
        return -1;
    }
    if (s.empty()) {
        return -1;
    }

    std::string result;
    for (auto &c : s) {
        if(!std::ispunct(c)) {
            result += c;
        }
    }
    std::cout << result << std::endl;
    return 0;
}

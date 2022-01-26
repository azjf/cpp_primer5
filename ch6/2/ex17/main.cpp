#include <iostream>

bool hasupper(const std::string &s)
{
    bool ret = false;
    for (auto &c : s) {
        if (std::isupper(c)) {
            ret = true;
            break;
        }
    }
    return ret;
}

void tolower(std::string &s) {
    for (auto &c : s) {
        c = std::tolower(c);
    }
}

int main()
{
    std::string s("Hello");
    std::cout << (hasupper(s) ? "true" : "false") << std::endl;
    tolower(s);
    std::cout << s << std::endl;
    return 0;
}

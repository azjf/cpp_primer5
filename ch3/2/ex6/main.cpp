#include <iostream>

int main()
{
    std::string s("abcd");
    for (auto &c : s) {
        c = 'X';
    }
    std::cout << s << std::endl;
    return 0;
}

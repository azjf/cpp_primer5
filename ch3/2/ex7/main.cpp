#include <iostream>

int main()
{
    std::string s("abcd");
    for (char c : s) {
        c = 'X';
    }
    std::cout << s << std::endl;
    return 0;
}

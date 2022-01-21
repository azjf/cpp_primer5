#include <iostream>

int main()
{
    std::string s("abcd");
    decltype(s.size()) i = 0;
    while (i < s.size()) {
        s[i++] = 'X';
    }
    std::cout << s << std::endl;

    s = "abcd";
    for (decltype(s.size()) i = 0; i < s.size(); ++i) {
        s[i] = 'X';
    }
    std::cout << s << std::endl;

    return 0;
}

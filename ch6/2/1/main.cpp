#include <iostream>

std::string::size_type find_char(const std::string &s, char c,
        std::string::size_type &occurs)
{
    auto ret = s.size();
    for (decltype(ret) i = 0; i != s.size(); ++i) {
        if (s[i] == c) {
            if (ret == s.size()) {
                ret = i;
            }
            ++occurs;
        }
    }
    return ret;
}

int main()
{
    std::string s("hello");
    decltype(s.size()) ctr = 0;
    auto index= find_char(s, 'o', ctr);
    std::cout << index << " " << ctr << std::endl;
    return 0;
}

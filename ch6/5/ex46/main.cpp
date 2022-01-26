#include <iostream>

inline bool isShorter(const std::string &s1, const std::string &s2)
//constexpr bool isShorter(const std::string &s1, const std::string &s2)
{
    return s1.size() < s2.size();
}

int main()
{
    isShorter("hello", "hi");
    return 0;
}

#include <iostream>
#include <cstring>

int main()
{
    std::string s1("hello"), s2 = s1;
    std::cout << (s1 == s2 ? "true" : "false") << std::endl;

    char ca1[] = "hello", ca2[] = "hello";
    std::cout << (std::strcmp(ca1, ca2) == 0 ? "true" : "false") << std::endl;
    return 0;
}

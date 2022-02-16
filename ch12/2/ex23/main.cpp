#include <iostream>
#include <cstring>

int main()
{
    const char *pc1 = "hello", *pc2 = "world";
    size_t str1_len = std::strlen(pc1), str2_len = std::strlen(pc2);
    char *pc = new char[str1_len + str2_len + 1]();
    for (size_t i = 0; i != str1_len; ++i) {
        pc[i] = pc1[i];
    }
    for (size_t i = 0; i != str2_len; ++i) {
        pc[i + str1_len] = pc2[i];
    }
    std::cout << pc << std::endl;

    std::string s1("hello"), s2("world");
    std::string s(s1 + s2);
    std::cout << s << std::endl;
    return 0;
}

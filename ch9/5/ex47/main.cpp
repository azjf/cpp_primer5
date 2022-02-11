#include <iostream>

int main()
{
    std::string s("ab2c3d7R4E6");
    std::string numbers("0123456789");

    std::string::size_type pos = 0;
    while ((pos = s.find_first_of(numbers, pos)) != std::string::npos) {
        std::cout << s[pos] << " ";
        ++pos;
    }
    std::cout << std::endl;
    decltype(pos) l = 0, r = 0;
    while ((r = s.find_first_of(numbers, r)) != std::string::npos) {
        while (l != r) {
            std::cout << s[l++] << " ";
        }
        ++r;
        l = r;
    }
    while (l != s.size()) {
        std::cout << s[l++] << " ";
    }
    std::cout << std::endl;

    l = 0, r = 0;
    while ((r = s.find_first_not_of(numbers, r)) != std::string::npos) {
        while (l != r) {
            std::cout << s[l++] << " ";
        }
        ++r;
        l = r;
    }
    while (l != s.size()) {
        std::cout << s[l++] << " ";
    }
    std::cout << std::endl;
    pos = 0;
    while ((pos = s.find_first_not_of(numbers, pos)) != std::string::npos) {
        std::cout << s[pos] << " ";
        ++pos;
    }
    std::cout << std::endl;
    return 0;
}

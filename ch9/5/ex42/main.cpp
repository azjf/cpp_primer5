#include <iostream>
#include <vector>

int main()
{
    std::string s(100, '\0');
    std::cout << s.size() << " " << s.capacity() << std::endl;
    for (size_t i = 0; i != 100; ++i) {
        s[i] = 'a';
        std::cout << s.size() << " " << s.capacity() << std::endl;
    }
    return 0;
}

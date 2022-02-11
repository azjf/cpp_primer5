#include <iostream>
#include <vector>

int main()
{
    std::vector<std::string> svec1{"123", "456", "789"};
    int res1 = 0;
    for (const auto &s : svec1) {
        res1 += std::stoi(s);
    }
    std::cout << res1 << std::endl;

    std::vector<std::string> svec2{"12.3", "45.6", "78.9"};
    double res2 = 0;
    for (const auto &s : svec2) {
        res2 += std::stoi(s);
    }
    std::cout << res2 << std::endl;
    return 0;
}

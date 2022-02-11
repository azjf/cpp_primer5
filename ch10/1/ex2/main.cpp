#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<std::string> ivec;
    std::string s;
    while (std::cin >> s) {
        ivec.push_back(s);
    }

    std::string val("hello");
    std::cout << std::count(ivec.cbegin(), ivec.cend(), val)
        << std::endl;
    return 0;
}

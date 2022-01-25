#include <iostream>
#include <vector>

int main()
{
    std::string rsp;
    do {
        std::string s1, s2;
        if (std::cin >> s1 >> s2) {
            std::cout << (s1.size() < s2.size() ? s1 : s2)
                << std::endl;
        } else {
            break;
        }
        std::cin >> rsp;
    } while (!rsp.empty() && rsp[0] != 'n');
    return 0;
}

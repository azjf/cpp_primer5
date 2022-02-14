#include <iostream>
#include <vector>
#include <set>

int main()
{
    std::vector<std::pair<std::string, int>> pvec1, pvec2, pvec3;
    std::string s;
    while (std::cin >> s) {
        int n = 0;
        std::cin >> n;
        pvec1.push_back({s, n});
        pvec2.push_back(std::make_pair(s, n));
        pvec3.push_back(std::pair<std::string, int>(s, n));
    }
    return 0;
}

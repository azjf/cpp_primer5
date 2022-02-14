#include <iostream>
#include <vector>
#include <set>

int main()
{
    std::vector<std::pair<std::string, int>> pvec;
    std::string s;
    while (std::cin >> s) {
        int n = 0;
        std::cin >> n;
        pvec.push_back({s, n});
        //pvec.push_back(std::make_pair(s, n));
    }
    return 0;
}

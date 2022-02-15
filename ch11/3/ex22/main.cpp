#include <iostream>
#include <vector>
#include <map>
#include <iterator>

int main()
{
    std::map<std::string, std::vector<int>> smap;
    std::pair<std::string, std::vector<int>> p{"hello", {1}};
    std::pair<std::string, std::vector<int>> p2("hello", {1});
    std::pair<std::map<std::string, std::vector<int>>::iterator, bool>
        ret = smap.insert(p);
    return 0;
}

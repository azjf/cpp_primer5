#include <iostream>
#include <vector>
#include <map>

int main()
{
    std::map<std::string, std::vector<int>> smap{
        {"hello", {1, 2}},
        {"world", {3, 4}} };
    smap["hi"] = {5, 6};
    std::cout << smap.size() << std::endl;
    return 0;
}

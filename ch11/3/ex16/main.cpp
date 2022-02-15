#include <iostream>
#include <map>

int main()
{
    std::map<std::string, int> smap{ {"hello", 1} };
    auto map_it = smap.begin();
    map_it->second = 2;
    return 0;
}

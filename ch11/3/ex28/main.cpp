#include <iostream>
#include <vector>
#include <map>

int main()
{
    std::map<std::string, std::vector<int>> smap{ {"hello", {1, 2}} };
    //auto ret = smap.find("hello");
    std::map<std::string, std::vector<int>>::iterator ret = smap.find("hello");
    return 0;
}

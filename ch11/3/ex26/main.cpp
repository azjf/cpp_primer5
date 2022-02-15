#include <iostream>
#include <vector>
#include <map>

int main()
{
    std::map<std::string, int> smap{ {"hello", 1} };
    std::string key = "hello";
    int val = smap[key];
    std::cout << val << std::endl;

    std::cout << smap[key + " "] << std::endl;
    return 0;
}

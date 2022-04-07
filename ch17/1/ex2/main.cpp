#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>

int main()
{
    std::tuple<std::string, std::vector<std::string>,
        std::pair<std::string, int>>
            t{"hello", {"hello", "world"}, {"hello", 1}};
    return 0;
}

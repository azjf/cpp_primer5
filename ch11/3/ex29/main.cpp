#include <iostream>
#include <vector>
#include <map>

int main()
{
    std::multimap<std::string, std::string> authors{
        {"hello", "world1"},
        {"hello", "world2"},
        {"hi", "world1"} };
    auto pos = authors.equal_range("hello");
    authors.erase(pos.first, pos.second);

    pos = authors.equal_range("hello2");
    authors.erase(pos.first, pos.second);
    return 0;
}

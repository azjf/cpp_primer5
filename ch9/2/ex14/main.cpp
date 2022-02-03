#include <iostream>
#include <list>
#include <vector>

int main()
{
    std::list<const char *> slist{"hello", "world"};
    std::vector<std::string> svec1(slist.cbegin(), slist.cend());
    std::vector<std::string> svec2;
    svec2.assign(slist.cbegin(), slist.cend());
    return 0;
}

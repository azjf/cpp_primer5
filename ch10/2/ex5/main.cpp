#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

int main()
{
    std::vector<const char *> roster1{"hello", "world"};
    std::list<const char *> roster2{"hello", "world"};
    std::cout << (std::equal(roster1.cbegin(), roster1.cbegin(), roster2) ?
            "true" : "false") << std::endl;
    return 0;
}

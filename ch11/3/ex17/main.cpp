#include <iostream>
#include <vector>
#include <set>
#include <iterator>

int main()
{
    std::multiset<std::string> c{"hello", "world", "hello"};
    std::vector<std::string> v{"hi", "world"};
    std::copy(v.begin(), v.end(), std::inserter(c, c.end()));
    //std::copy(v.begin(), v.end(), std::back_inserter(c));
    std::copy(c.begin(), c.end(), std::inserter(v, v.end()));
    std::copy(c.begin(), c.end(), std::back_inserter(v));
    return 0;
}

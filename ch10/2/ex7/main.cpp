#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

int main()
{
    std::vector<int> vec;
    std::list<int> lst;
    int i;
    while (std::cin >> i) {
        lst.push_back(i);
    }
    //std::copy(lst.cbegin(), lst.cend(), vec.begin());
    std::copy(lst.cbegin(), lst.cend(), std::back_inserter(vec));

    std::vector<int> vec2;
    vec2.reserve(10);
    //std::fill_n(vec2.begin(), 10, 0);
    std::fill_n(std::back_inserter(vec2), 10, 0);
    std::cout << vec2.size() << std::endl;
    return 0;
}

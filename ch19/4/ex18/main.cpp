#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <functional>

int main()
{
    std::vector<std::string> svec{"hello", "world", "", ""};

    std::function<bool (const std::string &)> empty(&std::string::empty);
    std::cout << std::count_if(svec.cbegin(), svec.cend(), empty) << std::endl;

    std::cout << std::count_if(svec.cbegin(), svec.cend(),
                std::mem_fn(&std::string::empty)) << std::endl;

    std::cout << std::count_if(svec.cbegin(), svec.cend(),
                std::bind(&std::string::empty, std::placeholders::_1))
        << std::endl;
    return 0;
}

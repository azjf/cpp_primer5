#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include <numeric>

int main()
{
    try {
        throw std::overflow_error("e");
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        std::abort();
    }
    return 0;
}

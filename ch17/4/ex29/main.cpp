#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <random>

unsigned my_random(unsigned seed)
{
    static std::default_random_engine e(seed);
    static std::uniform_int_distribution<unsigned> u(0, 9);
    return u(e);
}

int main()
{
    for (int i = 0; i != 10; ++i) {
        std::cout << my_random(time(0)) << " ";
    }
    std::cout << std::endl;
    return 0;
}

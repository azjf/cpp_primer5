#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <random>
#include <ctime>

std::vector<unsigned> bad_randVec()
{
    std::default_random_engine e;
    std::uniform_int_distribution<unsigned> u(0, 9);
    std::vector<unsigned> ret;
    for (std::size_t i = 0; i < 100; ++i) {
        ret.push_back(u(e));
    }
    return ret;
}

std::vector<unsigned> good_randVec()
{
    static std::default_random_engine e;
    static std::uniform_int_distribution<unsigned> u(0, 9);
    std::vector<unsigned> ret;
    for (std::size_t i = 0; i < 100; ++i) {
        ret.push_back(u(e));
    }
    return ret;
}

bool play(bool) { return true; }

int main()
{
    {
    std::default_random_engine e;
    for (std::size_t i = 0; i < 10; ++i) {
        std::cout << e() << " ";
    }
    std::cout << std::endl;
    }

    {
    std::uniform_int_distribution<unsigned> u(0, 9);
    std::default_random_engine e;
    for (std::size_t i = 0; i < 10; ++i) {
        std::cout << u(e) << " ";
    }
    std::cout << std::endl;

    std::cout << "min: " << e.min() << " max: " << e.max() << std::endl;

    std::vector<unsigned> v1(bad_randVec());
    std::vector<unsigned> v2(bad_randVec());
    std::cout << ((v1 == v2) ? "equal" : "not equal") << std::endl;

    std::default_random_engine e1;
    std::default_random_engine e2(2147483646);
    std::default_random_engine e3;
    e3.seed(32767);
    std::default_random_engine e4(32767);
    for (std::size_t i = 0; i != 100; ++i) {
        if (e1() == e2()) {
            std::cout << "unseeded match at iteration: " << i << std::endl;
        }
        if (e3() != e4()) {
            std::cout << "seeded differs at iteration: " << i << std::endl;
        }
    }
    }

    {
    std::default_random_engine e1(time(0));
    std::default_random_engine e;
    std::uniform_real_distribution<double> u(0, 1);
    for (std::size_t i = 0; i < 10; ++i) {
        std::cout << u(e) << " ";
    }
    std::cout << std::endl;
    }

    {
    std::uniform_real_distribution<> u(0, 1);

    std::default_random_engine e;
    std::normal_distribution<> n(4, 1.5);
    std::vector<unsigned> vals(9);
    for (std::size_t i = 0; i != 200; ++i) {
        unsigned v = std::lround(n(e));
        if (v < vals.size()) {
            ++vals[v];
        }
    }
    for (std::size_t j = 0; j != vals.size(); ++j) {
        std::cout << j << ": " << std::string(vals[j], '*') << std::endl;
    }
    }

    std::string resp;
    std::default_random_engine e;
    //std::bernoulli_distribution b;
    std::bernoulli_distribution b(0.55);
    do {
        bool first = b(e);
        std::cout << (first ? "We go first" : "You get to go first")
            << std::endl;
        std::cout << ((play(first)) ? "sorry, you lost" : "congrats, you won")
            << std::endl;
    } while (std::cin >> resp && resp[0] == 'y');
    return 0;
}

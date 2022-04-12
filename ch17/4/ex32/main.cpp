#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <random>
#include <ctime>

bool play(bool) { return true; }

int main()
{
    std::default_random_engine e;
    //std::bernoulli_distribution b;
    std::bernoulli_distribution b(0.55);
    do {
        std::string resp;
        bool first = b(e);
        std::cout << (first ? "We go first" : "You get to go first")
            << std::endl;
        std::cout << ((play(first)) ? "sorry, you lost" : "congrats, you won")
            << std::endl;
    } while (std::cin >> resp && resp[0] == 'y');
    return 0;
}

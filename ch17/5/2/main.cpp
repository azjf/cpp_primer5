#include <ios>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <random>
#include <ctime>

int main()
{
    char ch;
    std::cin >> std::noskipws;
    while (std::cin >> ch) {
        std::cout << ch;
    }
    std::cin >> std::skipws;
    return 0;
}

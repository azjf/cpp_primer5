#include <iostream>
#include <fstream>
#include <sstream>

int main()
{
    std::ifstream input("infile");
    if (!input) {
        return -1;
    }

    std::string line, word;
    while (std::getline(input, line)) {
        std::istringstream iss(line);
        while (iss >> word) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

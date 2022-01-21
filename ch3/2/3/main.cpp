#include <iostream>

int main()
{
    std::string line;
    while (std::getline(std::cin, line)) {
        if (!line.empty()) {
            if (line.size() > 8) {
                std::cout << line << std::endl;
            }
        }
    }
    return 0;
}

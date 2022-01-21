#include <iostream>

int main()
{
    std::string line;
    std::getline(std::cin, line);
    std::cout << line << std::endl;

    std::string word;
    while (std::cin >> word) {
        std::cout << word << std::endl;
    }

    return 0;
}

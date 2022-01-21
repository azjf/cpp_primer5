#include <iostream>

int main()
{
    std::string sum, line;
    while (std::getline(std::cin, line)) {
        sum += line + " ";
    }
    std::cout << sum << std::endl;
    return 0;
}

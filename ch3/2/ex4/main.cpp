#include <iostream>

int main()
{
    std::string line1, line2;
    std::getline(std::cin, line1);
    std::getline(std::cin, line2);

    if (line1 == line2) {
        std::cout << "equals" << std::endl;
    } else {
        std::cout << (line1 > line2 ? line1 : line2) << std::endl;
    }

    if (line1.size() == line2.size()) {
        std::cout << "equals: length" << std::endl;
    } else {
        std::cout
            << (line1.size() > line2.size() ? line1 : line2)
            << std::endl;
    }

    return 0;
}

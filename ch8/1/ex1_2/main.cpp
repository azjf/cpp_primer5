#include <iostream>

std::istream &f(std::istream &is)
{
    std::string line;
    while(std::getline(is, line)) {
        std::cout << line << std::endl;
    }

    is.clear();
    return is;
}

int main()
{
    f(std::cin);
    return 0;
}

#include <iostream>
#include <sstream>

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
    std::istringstream iss("hello world\nhi world");
    f(iss);
    return 0;
}

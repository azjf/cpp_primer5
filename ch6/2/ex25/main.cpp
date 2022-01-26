#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 3) {
        std::cerr << "there must be two arguments" << std::endl;
        return -1;
    }
    std::string s(argv[1]);
    s += argv[2];
    std::cout << s << std::endl;
    return 0;
}

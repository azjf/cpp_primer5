#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 5) {
        std::cerr << "there must be 2 arguments" << std::endl;
        return -1;
    }
    for (int i = 1; i != argc ; ++i) {
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

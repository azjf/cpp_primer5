#include <iostream>

void print(const int ia[10])
{
    for (size_t i = 0; i != 10; ++i) {
        std::cout << ia[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int ia[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print(ia);
    return 0;
}

#include <iostream>

void print(const int *beg, const int *end)
{
    while (beg != end) {
        std::cout << *beg++ << " ";
    }
    std::cout << std::endl;
}

void print(const int *parr, size_t sz)
{
    for (size_t i = 0; i != sz; ++i) {
        std::cout << parr[i] << " ";
    }
    std::cout << std::endl;
}

void print(const int (&arr)[2])
{
    for (auto &i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int i = 0, j[2] = {0, 1};

    //print(std::begin(&i), std::end(&i));
    print(std::begin(j), std::end(j));

    print(&i, 1);
    print(j, 2);

    print(j);
    return 0;
}

#include <iostream>

void reset(int &i)
{
    i = 0;
}

int main()
{
    int v = 1;
    reset(v);
    std::cout << v << std::endl;
    return 0;
}

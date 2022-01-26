#include <iostream>

void swap(int &v1, int &v2)
{
    int tmp = v1;
    v1 = v2;
    v2 = tmp;
    return;
}

int main()
{
    int v1 = 1, v2 = 2;
    std::cout << v1 << " " << v2 << std::endl;
    swap(v1, v2);
    std::cout << v1 << " " << v2 << std::endl;
    return 0;
}

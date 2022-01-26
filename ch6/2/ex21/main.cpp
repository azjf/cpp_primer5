#include <iostream>

int compare(int v1, const int *p2) {
    return v1 > *p2 ? v1 : *p2;
}

int main()
{
    int v1 = 1, v2 = 2;
    std::cout << compare(v1, &v2) << std::endl;
    return 0;
}

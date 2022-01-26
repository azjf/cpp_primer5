#include <iostream>

void swap(int *&p1, int *&p2) {
    int *tmp = p1;
    p1 = p2;
    p2 = tmp;
}

int main()
{
    int v1 = 1, v2 = 2, *p1 = &v1, *p2 = &v2;
    swap(p1, p2);
    std::cout << *p1 << " " << *p2 << std::endl;
    return 0;
}

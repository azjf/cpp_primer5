#include <iostream>

int main()
{
    int a = 1;
    int *p = nullptr;
    p = &a;
    *p = 2;
    return 0;
}

#include <iostream>

typedef int arrT[10];
using arrT1 = int[10];
arrT* func(int i);

int (*func(int i))[10];

auto func(int i) -> int (*)[10];

int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};
decltype(odd) *arrPtr(int i)
{
    return (i % 2) ? &odd : &even;
}

int main()
{
    int (*ret)[5] = arrPtr(1);
    decltype(odd) *ret2 = arrPtr(2);
    return 0;
}

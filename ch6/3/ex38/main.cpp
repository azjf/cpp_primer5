#include <iostream>

int odd[] = {1, 3, 5, 7, 9};
int even[] = {2, 4, 6, 8, 10};

decltype(odd) &arrPtr(int i)
{
    return (i & 2) ? odd : even;
}

int main()
{
    int (&ret)[5] = arrPtr(1);
    decltype(odd) &ret2 = arrPtr(2);
    return 0;
}

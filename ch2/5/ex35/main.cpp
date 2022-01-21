#include <iostream>

int main()
{
    const int i = 42;
    auto j = i; const auto &k = i; auto *p = &i;
    const auto j2 = i, &k2 = i;

    int a = 1;
    j = 43;
    //k = 43;
    p = &a;
    //*p = 43;
    //j2 = 43;
    //k2 = 43;
    
    auto &k3 = i;
    //k3 = 43;
    return 0;
}

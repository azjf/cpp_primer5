#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <cstring>

template <typename T> void f1(T, T) {}
template <typename T1, typename T2> void f2(T1, T2) {}

int main()
{
    int i = 0, j = 42, *p1 = &i, *p2 = &j;
    const int *cp1 = &i, *cp2 = &j;
    f1(p1, p2);
    f2(p1, p2);
    f1(cp1, cp2);
    f2(cp1, cp2);
    //f1(p1, cp2);
    f2(p1, cp2);
    return 0;
}

#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <cstring>

template <typename T> void g(T val) {}
template <typename T> void g2(const T &val) {}

int main()
{
    int i = 0;
    const int ci = i;
    g(i);
    g(ci);
    g(i * ci);
    g2(i);
    g2(ci);
    g2(i * ci);
    return 0;
}

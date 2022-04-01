#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <cstring>

template <typename T> T calc(T t, int) { return t; }
template <typename T> T fcn(T t1, T) { return t1; }

int main()
{
    double d;
    float f;
    char c;
    calc(c, 'c');
    calc(d, f);
    fcn(c, 'c');
    //fcn(d, f);
    return 0;
}

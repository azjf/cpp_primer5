#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <cstring>

template <typename T>
int compare(const T &v1, const T &v2)
{
    if (v1 < v2) {
        return -1;
    }
    if (v2 < v1) {
        return 1;
    }
    return 0;
}

//void f(const const) {}

int main()
{
    //compare("hello", "worldd");
    compare<const char *>("hello", "worldd");
    return 0;
}

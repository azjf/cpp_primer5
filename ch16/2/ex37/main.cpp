#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <cstring>

int main()
{
    int i = 0;
    double d = 0;
    //std::max(i, d);
    std::max<double>(i, d);
    return 0;
}

#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include <numeric>

int main()
{
    std::range_error r("error");
    //throw r;

    std::exception *p = &r;
    //throw *p;
    throw p;
    return 0;
}

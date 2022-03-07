#include <iostream>
#include <vector>
#include <algorithm>
#include "HasPtr.h"

int main()
{
    std::vector<HasPtr> vec{HasPtr("hello"), HasPtr("world")};
    std::sort(vec.begin(), vec.end());
    return 0;
}

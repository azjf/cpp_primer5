#include <iostream>
#include <memory>
#include <vector>
#include "Vec.h"

int main()
{
    typedef Vec<std::string> StrVec;
    StrVec svec;
    svec = {"hello", "word"};

    Vec<int> ivec;
    ivec = {1, 2, 3, 4};
    return 0;
}

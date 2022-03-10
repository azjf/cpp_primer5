#include <iostream>
#include "StrVec.h"

int main()
{
    StrVec sv{"hello", "world"};
    for (auto p = sv.begin(); p != sv.end(); ++p) {
        std::cout << *p << std::endl;
    }
    return 0;
}

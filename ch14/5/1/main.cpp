#include <iostream>
#include <memory>
#include <vector>
#include "StrVec.h"

int main()
{
    StrVec svec;
    svec = {"", "hello"};
    const StrVec cvec = svec;
    if (svec.size() && svec[0].empty()) {
        svec[0] = "zero";
        //cvec[0] = "Zip";
    }
    return 0;
}

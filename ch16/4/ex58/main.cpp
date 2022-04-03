#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <list>
#include <type_traits>
#include <cstring>

#include "StrVec.h"
#include "Vec.h"

int main()
{
    {
    StrVec svec;
    svec.emplace_back(10, 'c');
    std::string s1("the"), s2(" end");
    svec.emplace_back(s1 + s2);
    std::cout << svec[0] << " " << svec[1] << std::endl;
    }

    {
    Vec<std::string> svec;
    svec.emplace_back(10, 'c');
    std::string s1("the"), s2(" end");
    svec.emplace_back(s1 + s2);
    std::cout << svec[0] << " " << svec[1] << std::endl;
    }
    return 0;
}

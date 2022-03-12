#include <iostream>
#include <vector>
#include "String.h"

int main()
{
    std::vector<String> svec;
    svec.push_back("1");
    svec.push_back("2");
    svec.push_back("3");
    svec.push_back("4");
    svec.push_back("5");

    String s("6");
    svec.push_back(s);
    return 0;
}

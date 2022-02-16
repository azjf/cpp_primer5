#include <iostream>
#include "StrBlob.h"

int main()
{
    StrBlob sb1{"hello", "world"};
    const StrBlob sb2(sb1);
    sb1.push_back("hello");
    sb1 = {"hi", "world"};
    std::cout << sb2.size() << std::endl;
    return 0;
}

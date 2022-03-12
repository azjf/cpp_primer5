#include <iostream>
#include "String.h"

int main()
{
    String s("hello");
    std::cout << s << std::endl;
    String s2(s), s3 = s;
    s3 = s;
    return 0;
}

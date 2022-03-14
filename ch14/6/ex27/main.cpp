#include <iostream>
#include <memory>
#include <vector>
#include "StrBlob.h"

int main()
{
    StrBlob sb{"hello", "world"};
    StrBlobPtr sbp(sb, 0);
    std::cout << sbp.deref() << std::endl;
    std::cout << (++sbp).deref() << std::endl;
    std::cout << (--sbp).deref() << std::endl;
    std::cout << sbp++.deref() << std::endl;
    std::cout << sbp--.deref() << std::endl;
    return 0;
}

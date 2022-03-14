#include <iostream>
#include <memory>
#include <vector>
#include "StrBlob.h"

int main()
{
    StrBlob sb{"hello", "world", "hi"};
    StrBlobPtr sbp(sb, 0);
    std::cout << (sbp + 2).deref() << std::endl;
    sbp += 2;
    std::cout << (sbp - 2).deref() << std::endl;
    return 0;
}

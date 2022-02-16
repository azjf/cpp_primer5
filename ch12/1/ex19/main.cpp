#include <iostream>
#include "StrBlob.h"
#include "StrBlobPtr.h"

int main()
{
    StrBlob sb{"hello", "world"};
    StrBlobPtr sbp1(sb.begin());
    StrBlobPtr sbp2(sb.end());
    std::cout << sbp1.deref() << std::endl;
    return 0;
}

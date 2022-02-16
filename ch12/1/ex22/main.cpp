#include <iostream>
#include "StrBlob.h"
#include "ConstStrBlobPtr.h"

int main()
{
    const StrBlob sb{"hello", "world"};
    ConstStrBlobPtr sbp1(sb.begin());
    ConstStrBlobPtr sbp2(sb.end());
    //sbp1.deref() = "hi";
    std::cout << sbp1.deref() << std::endl;
    return 0;
}

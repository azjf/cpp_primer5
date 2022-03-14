#include <iostream>
#include <memory>
#include <vector>
#include "StrBlob.h"
#include "StrBlobPPtr.h"

int main()
{
    StrBlob sb = {"hello", "world"};
    StrBlobPtr sbp(sb);
    StrBlobPPtr sbpp(sbp);
    std::cout << sbpp->size() << std::endl;
    return 0;
}

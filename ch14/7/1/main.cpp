#include <iostream>
#include <memory>
#include <vector>
#include "StrBlob.h"

int main()
{
    StrBlob a1 = {"hi", "bye", "now"};
    StrBlobPtr p(a1);
    *p = "okay";
    std::cout << p->size() << std::endl;
    std::cout << (*p).size() << std::endl;
    return 0;
}

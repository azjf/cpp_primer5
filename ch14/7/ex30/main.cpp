#include <iostream>
#include <memory>
#include <vector>
#include "StrBlob.h"
#include "ConstStrBlobPtr.h"

int main()
{
    StrBlob a1 = {"hi", "bye", "now"};
    StrBlobPtr p(a1);
    *p = "okay";
    std::cout << p->size() << std::endl;
    std::cout << (*p).size() << std::endl;

    ConstStrBlobPtr cp(a1);
    //*cp = "okay";
    std::cout << cp->size() << std::endl;
    std::cout << (*cp).size() << std::endl;
    return 0;
}

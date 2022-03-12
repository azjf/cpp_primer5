#include <iostream>
#include <memory>
#include "StrBlob.h"

int main()
{
    auto p = std::make_shared<int>(42);
    std::weak_ptr<int> wp(p);

    if (std::shared_ptr<int> np = wp.lock()) {
    }

    StrBlob sb{"hello", "world"};
    StrBlobPtr sbp1(sb.begin());
    StrBlobPtr sbp2(sb.end());
    std::cout << sbp1.deref() << std::endl;

    std::string s("hi");
    sb.push_back("hi");
    sb.push_back(s);
    return 0;
}

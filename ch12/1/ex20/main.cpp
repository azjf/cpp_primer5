#include <iostream>
#include "StrBlob.h"
#include "StrBlobPtr.h"

int main()
{
    StrBlob sb;
    std::string line;
    while (std::getline(std::cin, line)) {
        sb.push_back(line);
    }

    StrBlobPtr sbp(sb.begin());
    for (StrBlob::size_type i = 0; i != sb.size(); ++i) {
        std::cout << sbp.deref() << std::endl;
        sbp.incr();
    }
    return 0;
}

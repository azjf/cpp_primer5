#include <iostream>
#include <memory>
#include <vector>
#include "StrBlob.h"
#include "StrVec.h"
#include "String.h"

int main()
{
    StrBlob sb{"", "world"};
    sb[0] = "hello";
    std::cout << sb[0] << std::endl;
    const StrBlob &csb = sb;
    //csb[0] = "hello";

    StrBlobPtr sbp(sb, 0);
    sbp[0] = "hello";
    std::cout << sbp[0] << std::endl;
    const StrBlobPtr &csbp = sbp;
    //csbp[0] = "hello";

    StrVec svec;
    svec = {"hello", "hello"};
    svec[0] = "hello";
    std::cout << svec[0] << std::endl;
    const StrVec &csvec = svec;
    //csvec[0] = "hello";

    String s("_ello");
    s[0] = 'h';
    std::cout << s << std::endl;
    const String &cs = s;
    //cs[0] = 'h';
    return 0;
}

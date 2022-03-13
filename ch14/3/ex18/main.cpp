#include <iostream>
#include <memory>
#include <vector>
#include "StrBlob.h"
#include "StrVec.h"
#include "String.h"

int main()
{
    StrBlob sb1{"hello", "world"}, sb2{"hello", "world"};
    StrBlob sb3{"hello", "worle"};
    std::cout << (sb1 == sb2 ? "true" : "false") << std::endl;
    std::cout << (sb1 < sb3 ? "true" : "false") << std::endl;

    StrBlobPtr sbp1(sb1, 0), sbp2(sb1, 0);
    StrBlobPtr sbp3(sb1, 1);
    std::cout << (sbp1 == sbp2 ? "true" : "false") << std::endl;
    std::cout << (sbp1 < sbp3 ? "true" : "false") << std::endl;

    StrVec sv1, sv2;
    sv1.push_back("hello");
    sv1.push_back("world");
    sv2.push_back("hello");
    sv2.push_back("world");
    StrVec sv3;
    sv3.push_back("hello");
    sv3.push_back("worle");
    std::cout << (sv1 == sv2 ? "true" : "false") << std::endl;
    std::cout << (sv1 < sv3 ? "true" : "false") << std::endl;

    String s1("hello"), s2("hello");
    String s3("hellp");
    std::cout << (s1 == s2 ? "true" : "false") << std::endl;
    std::cout << (s1 < s3 ? "true" : "false") << std::endl;
    return 0;
}

#include <iostream>

bool lengthCompare(const std::string &s1, const std::string &s2)
{
    std::cout << s1 << " " << s2 << std::endl;
    return true;
}

void ff(unsigned int) {}

int main()
{
    bool (*pf)(const std::string &, const std::string &);

    pf = lengthCompare;
    pf = &lengthCompare;
    bool b1 = pf("hello", "goodbye");
    bool b2 = (*pf)("hello", "goodbye");
    bool b3 = lengthCompare("hello", "goodbye");

    std::string::size_type sumLength(const std::string &, const std::string &);
    bool cstringCompare(const char *, const char *);
    pf = 0;
    pf = nullptr;
    //pf = sumLength;
    //pf = cstringCompare;
    pf = lengthCompare;

    void ff(int*);
    void ff(unsigned int);
    void (*pf1)(unsigned int) = ff;
    //void (*pf2)(int) = ff;
    //double (*pf3)(int*) = ff;

    void useBigger(const std::string &s1, const std::string &s2,
            bool pf(const std::string &, const std::string &));
    void useBigger(const std::string &s1, const std::string &s2,
            bool (*pf)(const std::string &, const std::string &));
    //useBigger(s1, s2, lengthCompare);

    typedef bool Func(const std::string &, const std::string &);
    typedef decltype(lengthCompare) Func2;
    typedef bool (*FuncP)(const std::string &, const std::string &);
    typedef decltype(lengthCompare) *FuncP2;
    void useBigger(const std::string &, const std::string &, Func);
    void useBigger(const std::string &, const std::string &, FuncP2);

    using F = int (int *, int);
    using PF = int (*)(int *, int);
    PF f1(int);
    //F f1(int):
    F *f1(int);
    int (*f1(int))(int *, int);
    auto f1(int) -> int (*)(int *, int);

    std::string::size_type sumLength(const std::string &, const std::string &);
    std::string::size_type largerLength(const std::string &, const std::string &);
    decltype(sumLength) *getFcn(const std::string &);
    return 0;
}

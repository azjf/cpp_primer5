#include <iostream>
#include <vector>

int main()
{
    int i = 0;
    double d = 0;
    std::string s("hello");
    char c = 'c';
    const std::string *ps = &s;
    char *pc = &c;
    void *pv;

    pv = const_cast<std::string*>(ps);
    pv = static_cast<void*>(const_cast<std::string*>(ps));

    i = *pc;
    i = static_cast<int>(*pc);

    pv = static_cast<void*>(&d);

    pc = static_cast<char*>(pv);
    return 0;
}

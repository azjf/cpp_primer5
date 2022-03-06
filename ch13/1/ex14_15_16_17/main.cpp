#include <iostream>
#include "numbered.h"

void f(numbered s)
{
    std::cout << s.mysn << std::endl;
}

void f2(const numbered &s)
{
    std::cout << s.mysn << std::endl;
}

int main()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);

    f2(a);
    f2(b);
    f2(c);
    return 0;
}

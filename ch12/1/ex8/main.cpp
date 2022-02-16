#include <iostream>

bool b() {
    int *p = new int;
    return p;
}

int main()
{
    std::cout << b() << std::endl;
    return 0;
}

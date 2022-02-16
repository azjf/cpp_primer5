#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<int> p1(new int(1)), p2, p3(p1);
    p2 = p1;
    return 0;
}

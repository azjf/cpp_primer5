#include <iostream>
#include <vector>

int main()
{
    int f(int, int);
    std::vector<int (*)(int, int)> pfvec;
    std::vector<decltype(f) *> pfvec2;
    return 0;
}

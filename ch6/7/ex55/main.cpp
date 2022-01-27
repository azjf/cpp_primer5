#include <iostream>
#include <vector>

int add(int v1, int v2) { return v1 + v2; }
int subtract(int v1, int v2) { return v1 - v2; }
int multiply(int v1, int v2) { return v1 * v2; }
int divide(int v1, int v2) { return v1 / v2; }

int main()
{
    int f(int, int);
    std::vector<int (*)(int, int)> pfvec{add, &subtract, multiply, divide};
    std::vector<decltype(f) *> pfvec2{add, &subtract, multiply, divide};
    return 0;
}

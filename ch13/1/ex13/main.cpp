#include <iostream>
#include <vector>
#include <memory>
#include "X.h"

void f1(X x) {}
void f2(X &x) {}

int main()
{
    X x1;
    X x2(x1);
    X x3 = x1;
    x3 = x1;

    f1(x1);
    f2(x1);

    X *px1 = new X();
    auto px2 = std::make_shared<X>();
    std::unique_ptr<X> x(px1);

    std::vector<X> vec;
    vec.push_back(x1);
    return 0;
}

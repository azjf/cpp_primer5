#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

struct LongDouble
{
    LongDouble(double = 0.0) {}
    operator double() { return 0; }
    operator float() { return 0; }
};

void calc(int) { std::cout << "calc(int)" << std::endl; }
void calc(LongDouble) { std::cout << "calc(LongDouble)" << std::endl; }

int main()
{
    double dval;
    calc(dval);
    return 0;
}

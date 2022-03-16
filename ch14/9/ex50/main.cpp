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

int main()
{
    LongDouble ldObj;
    //int ex1 = ldObj;
    float ex2 = ldObj;
    return 0;
}

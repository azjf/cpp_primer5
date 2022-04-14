#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include <numeric>

template <typename T>
void swap(T v1, T v2)
{
    //using std::swap;
    std::swap(v1.mem1, v2.mem1);
}

struct A1 { std::string mem1; };
struct A2 { int mem1; };

int main()
{
    swap(A1(), A1());
    swap(A2(), A2());
    return 0;
}

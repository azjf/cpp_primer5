#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include <numeric>

namespace AW
{
int print(int) { return 0; }
}

namespace Primer
{
double print(double) { return 0; }
}

using namespace AW;
using namespace Primer;

long double print(long double) { return 0; }

int main()
{
    print(1);
    print(3.1);
    return 0;
}

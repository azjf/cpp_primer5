#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include <numeric>

namespace Exercise
{
int ivar = 0;
double dvar = 0;
const int limit = 1000;
}

int ivar = 0;

//using Exercise::ivar;
//using Exercise::dvar;
//using Exercise::limit;

//using namespace Exercise;

void manip()
{
    //using Exercise::ivar;
    //using Exercise::dvar;
    //using Exercise::limit;

    using namespace Exercise;

    double dvar = 3.1416;
    int iobj = limit + 1;
    //++ivar;
    ++::ivar;
}

int main()
{
    return 0;
}

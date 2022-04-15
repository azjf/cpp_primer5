#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include <numeric>

class CAD {};
class Vehicle {};
class CADVehical : public CAD, Vehicle {};

class List {};
//class DbList : public List, public List {};

class iostream : public std::istream, public std::ostream {};

int main()
{
    return 0;
}

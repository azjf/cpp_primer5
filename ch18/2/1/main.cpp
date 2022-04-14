#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include <numeric>

namespace cplusplus_primer
{
class Sales_data {};

Sales_data operator+(const Sales_data &, const Sales_data &);

class Query
{
public:
    Query(const std::string &) {}
};

class Query_base {};
}

int main()
{
    cplusplus_primer::Query q = cplusplus_primer::Query("hello");
    return 0;
}

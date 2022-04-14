#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include <numeric>

#include "Sales_data.h"

cplusplus_primer::Sales_data cplusplus_primer::operator_plus(
        const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

namespace std
{
template <> struct hash<cplusplus_primer::Sales_data>;
}

template <> struct std::hash<cplusplus_primer::Sales_data>
{
    size_t operator()(const cplusplus_primer::Sales_data &s) const
    {
        return hash<string>()(s.bookNo)
        ^ hash<unsigned>()(s.units_sold)
        ^ hash<double>()(s.revenue);
    }
};

int member_name = 1;

namespace cplusplus_primer
{

int i = ::member_name;

namespace QueryLib
{
class Query {};
Query operator&(const Query &, const Query &);
}

namespace Bookstore
{
class Quote {};
class Disc_quote : public Quote {};
}

}

namespace cplusplus_primer
{
#include "FifthEd.h"
#include "FourthEd.h"
}

int i;
namespace
{
    int i;
}
namespace local
{
namespace
{
    int i;
}
}

int main()
{
    {
    using cplusplus_primer::Sales_data;
    Sales_data trans1, trans2;

    cplusplus_primer::QueryLib::Query q;

    cplusplus_primer::Query_base q5;
    cplusplus_primer::FourthEd::Query_base q4;

    local::i = 42;
    }

    namespace primer = cplusplus_primer;
    namespace Qlib = cplusplus_primer::QueryLib;
    Qlib::Query q;

    return 0;
}

#include <iostream>
#include <memory>
#include <vector>
#include "Sales_data.h"
#include "NoCopy.h"
#include "NoDtor.h"
#include "PrivateCopy.h"

int main()
{
    Sales_data sales_data;

    {
    Sales_data *p = new Sales_data;
    auto p2 = std::make_shared<Sales_data>();
    Sales_data item(*p);
    std::vector<Sales_data> vec;
    vec.push_back(*p2);
    delete p;
    }

    NoCopy nc;

    //NoDtor nd;
    NoDtor *p = new NoDtor();
    //delete p;

    PrivateCopy pc;
    return 0;
}

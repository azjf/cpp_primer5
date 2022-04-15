#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include <numeric>

#include "Sales_data.h"

int main()
{
    using avg_price = double (Sales_data::*)() const;
    //using p_avg_price = &Sales_data::avg_price;
    return 0;
}

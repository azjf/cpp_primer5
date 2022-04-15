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
    std::string Sales_data::*pbookNo = &Sales_data::bookNo;
    std::cout << Sales_data("hello").*pbookNo << std::endl;
    return 0;
}

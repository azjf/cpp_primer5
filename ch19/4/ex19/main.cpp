#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <functional>

#include "Sales_data.h"

bool greater(const Sales_data &sd, double price)
{
    return sd.avg_price() > price;
}

int main()
{
    std::vector<Sales_data> vec{Sales_data("hello"), Sales_data("world")};

    std::cout << *std::find_if(vec.cbegin(), vec.cend(),
            std::bind(greater, std::placeholders::_1, -1)) << std::endl;

    std::cout << *std::find_if(vec.cbegin(), vec.cend(),
            std::bind([] (const Sales_data &sd, double price)
                { return sd.avg_price() > price; }, std::placeholders::_1, -1))
        << std::endl;

    std::cout << *std::find_if(vec.cbegin(), vec.cend(),
            [] (const Sales_data &sd) { return sd.avg_price() > -1; })
        << std::endl;

    //std::function<double ()> avg_price(&Sales_data::avg_price);
    //std::cout << *std::find_if(vec.cbegin(), vec.cend(), avg_price) << std::endl;

    //std::cout << *std::find_if(vec.cbegin(), vec.cend(),
    //            std::mem_fn(&std::string::empty)) << std::endl;

    //std::cout << *std::find_if(vec.cbegin(), vec.cend(),
    //            std::bind(&std::string::empty, std::placeholders::_1))
    //    << std::endl;
    return 0;
}

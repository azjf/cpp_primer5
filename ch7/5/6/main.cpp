#include <iostream>
#include <string>
#include "Sales_data.h"

int main()
{
    std::string null_book = "9-999-99999-9";
    Sales_data item(null_book);
    item.combine(null_book);

    //item.combine("9-999-99999-9");
    item.combine(std::string("9-999-99999-9"));
    item.combine(Sales_data("9-999-99999-9"));
    item.combine(std::cin);
    return 0;
}

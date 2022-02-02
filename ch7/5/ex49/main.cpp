#include <iostream>
#include <string>
#include "Sales_data.h"

int main()
{
    std::string s = "9-999-99999-9";
    Sales_data i(s);
    i.combine(s);
    return 0;
}

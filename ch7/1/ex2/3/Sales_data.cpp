#include "Sales_data.h"

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    price = (numSold * price + rhs.numSold * rhs.price)
        / (numSold + rhs.numSold);
    numSold += rhs.numSold;
    return *this;
}

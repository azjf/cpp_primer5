#include "Sales_data.h"

Sales_data::Sales_data(std::istream &is)
{
    read(is, *this);
}

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    price = (numSold * price + rhs.numSold * rhs.price)
        / (numSold + rhs.numSold);
    numSold += rhs.numSold;
    return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

std::istream &read(std::istream &is, Sales_data &item)
{
    is >> item.bookNo >> item.numSold >> item.price;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.numSold << " "
        << item.price * item.numSold << " " << item.price;
    return os;
}

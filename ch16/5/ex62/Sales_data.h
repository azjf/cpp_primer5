#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
#include <iostream>

//template <class T> class std::hash;

struct Sales_data
{
    friend std::ostream &operator<<(std::ostream &, const Sales_data &);
    friend std::istream &operator>>(std::istream &, Sales_data &);
    friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);
    friend bool operator==(const Sales_data &lhs, const Sales_data &rhs);
    friend bool operator!=(const Sales_data &lhs, const Sales_data &rhs);
    friend class std::hash<Sales_data>;

    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) { }
    Sales_data(const std::string &s, unsigned n, double p) :
        bookNo(s), units_sold(n), revenue(p * n) { }
    Sales_data(std::istream &);
    //Sales_data(const Sales_data &);
    Sales_data(const Sales_data &) = default;
    //~Sales_data() {}
    ~Sales_data() = default;

    Sales_data &operator=(const Sales_data &rhs);
    Sales_data &operator+=(const Sales_data &rhs);

    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data &);
    double avg_price() const;

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);


namespace std
{
template <>
struct hash<Sales_data>
{
    typedef size_t result_type;
    typedef Sales_data argument_type;
    size_t operator()(const Sales_data &s) const;
};

inline
size_t hash<Sales_data>::operator()(const Sales_data &s) const
{
    return hash<string>()(s.bookNo)
        ^ hash<unsigned>()(s.units_sold)
        ^ hash<double>()(s.revenue);
}
}
#endif

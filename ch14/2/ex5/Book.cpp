#include <iostream>

#include "Book.h"

bool operator==(const Book &lhs, const Book &rhs)
{
    return (lhs.name == rhs.name)
        && (lhs.author == rhs.author) && (lhs.year == rhs.year);
}

std::istream &operator>>(std::istream &is, Book &book)
{
    is >> book.name >> book.author >> book.year;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Book &book)
{
    os << book.name << " " << book.author << " " << book.year;
    return os;
}

#include <iostream>

#include "Book.h"

bool operator==(const Book &lhs, const Book &rhs)
{
    return lhs.name == rhs.name
        && lhs.author == rhs.author && lhs.year == rhs.year;
}

bool operator!=(const Book &lhs, const Book &rhs)
{
    return !(lhs == rhs);
}

std::istream &operator>>(std::istream &is, Book &book)
{
    is >> book.name >> book.author >> book.year;
    if (!is) {
        book = Book();
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const Book &book)
{
    os << book.name << " " << book.author << " " << book.year;
    return os;
}

Book &Book::operator=(Book &&rhs)
{
    name = std::move(rhs.name);
    author = std::move(rhs.author);
    year = std::move(rhs.year);
    return *this;
}

Book &Book::operator=(const std::string &n)
{
    name = n;
    author = year = "";
    return *this;
}

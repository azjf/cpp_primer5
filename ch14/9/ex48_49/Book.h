#ifndef BOOK_H
#define BOOK_H
#include <string>

class Book
{
    friend bool operator==(const Book &lhs, const Book &rhs);
    friend bool operator!=(const Book &lhs, const Book &rhs);
    friend std::istream &operator>>(std::istream &, Book &);
    friend std::ostream &operator<<(std::ostream &, const Book &);

public:
    Book() = default;
    Book(const std::string &n) : name(n) { }
    Book(const std::string &n, const std::string &a) : name(n), author(a) { }
    Book(const std::string &n, const std::string &a, const std::string &y)
        : name(n), author(a), year(y) { }

    Book &operator=(const Book &) = default;
    Book &operator=(Book &&);
    Book &operator=(const std::string &);

    explicit operator bool() { return !name.empty(); }

private:
    std::string name;
    std::string author;
    std::string year;
};
#endif

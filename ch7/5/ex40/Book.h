#ifndef BOOK_H
#define BOOK_H
#include <string>

class Book
{
public:
    Book() = default;
    Book(const std::string &n) : name(n) { }
    Book(const std::string &n, const std::string &a) : name(n), author(a) { }
    Book(const std::string &n, const std::string &a, const std::string &y)
        : name(n), author(a), year(y) { }
    
private:
    std::string name;
    std::string author;
    std::string year;
};
#endif

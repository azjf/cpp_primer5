#ifndef BOOK_H
#define BOOK_H
#include <string>

class Book
{
public:
    Book(const std::string &n, const std::string &a, const std::string &y)
        : name(n), author(a), year(y) { }
    Book() : Book("", "", "") { }
    Book(const std::string &n) : Book(n, "", "") { }
    Book(const std::string &n, const std::string &a) : Book(n, a, "") { }
    
private:
    std::string name;
    std::string author;
    std::string year;
};
#endif

#include <iostream>
#include "Book.h"

int main()
{
    Book book1;
    Book book2("name");
    Book book3("name", "author");
    Book book4("name", "author", "2022");

    std::cout << book4 << std::endl;
    return 0;
}

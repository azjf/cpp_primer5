#include <iostream>
#include "Book.h"

int main()
{
    Book book1, book2;
    std::cin >> book1 >> book2;
    std::cout << (book1 == book2 ? "true" : "false") << std::endl;

    book1 = book2;
    std::cout << book2 << std::endl;
    book1 = std::move(book2);
    std::cout << book2 << std::endl;

    book1 = "hello";
    std::cout << book1 << std::endl;
    return 0;
}

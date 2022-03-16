#include <iostream>
#include "Book.h"

int main()
{
    Book book;
    std::cout << (book ? "true" : "false") << std::endl;
    std::cin >> book;
    std::cout << (book ? "true" : "false") << std::endl;
    return 0;
}

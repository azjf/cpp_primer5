#include <iostream>
#include "Book.h"

int main()
{
    Book book1, book2;
    std::cin >> book1 >> book2;
    std::cout << (book1 == book2 ? "true" : "false") << std::endl;
    return 0;
}

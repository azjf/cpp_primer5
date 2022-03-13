#include <iostream>
#include "Book.h"

int main()
{
    Book book("name", "author", "2022");
    std::cout << book << std::endl;
    return 0;
}

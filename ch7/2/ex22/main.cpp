#include <iostream>
#include "Person.h"

int main()
{
    Person person1;
    print(std::cout, person1) << std::endl;

    Person person2("hello");
    print(std::cout, person2) << std::endl;

    Person person3("hello", "world");
    print(std::cout, person3) << std::endl;

    Person person4(std::cin);
    print(std::cout, person4) << std::endl;
    return 0;
}

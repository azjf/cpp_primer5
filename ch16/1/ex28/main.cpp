#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include "My_shared_ptr.h"
#include "My_unique_ptr.h"

int main()
{
    {
    std::shared_ptr<int> pi(new int(123)), pi2(pi);
    std::cout << *pi << std::endl;
    std::cout << pi.use_count() << " " << pi2.use_count() << std::endl;
    pi.reset();
    std::cout << pi.use_count() << " " << pi2.use_count() << std::endl;
    pi.reset();
    std::cout << pi.use_count() << " " << pi2.use_count() << std::endl;
    pi.reset(new int(456));
    std::cout << *pi << std::endl;

    std::shared_ptr<std::string> ps(new std::string("hello"));
    std::cout << *ps << ": " << ps->size() << std::endl;
    }

    std::cout << std::endl;
    {
    My_shared_ptr<int> pi(new int(123)), pi2(pi);
    std::cout << *pi << std::endl;
    std::cout << pi.use_count() << " " << pi2.use_count() << std::endl;
    pi.reset();
    std::cout << pi.use_count() << " " << pi2.use_count() << std::endl;
    pi.reset();
    std::cout << pi.use_count() << " " << pi2.use_count() << std::endl;
    pi.reset(new int(456));
    std::cout << *pi << std::endl;

    My_shared_ptr<std::string> ps(new std::string("hello"));
    std::cout << *ps << ": " << ps->size() << std::endl;
    }

    std::cout << std::endl;
    {
    std::unique_ptr<int> pi(new int(123)), pi2;
    std::cout << *pi << std::endl;
    pi.reset();
    pi.reset();
    pi.reset(new int(456));
    std::cout << *pi << std::endl;
    }

    std::cout << std::endl;
    {
    My_unique_ptr<int> pi(new int(123)), pi2;
    std::cout << *pi << std::endl;
    pi.reset();
    pi.reset();
    pi.reset(new int(456));
    std::cout << *pi << std::endl;
    }
    return 0;
}

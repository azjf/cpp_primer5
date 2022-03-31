#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include "My_unique_ptr.h"
#include "DebugDelete.h"

int main()
{
    {
    std::unique_ptr<int, DebugDelete> pi(new int(123), DebugDelete()), pi2;
    std::cout << *pi << std::endl;
    pi.reset();
    pi.reset();
    pi.reset(new int(456));
    std::cout << *pi << std::endl;
    }

    std::cout << std::endl;
    {
    My_unique_ptr<int, DebugDelete> pi(new int(123), DebugDelete()), pi2;
    std::cout << *pi << std::endl;
    pi.reset();
    pi.reset();
    pi.reset(new int(456));
    std::cout << *pi << std::endl;
    }
    return 0;
}

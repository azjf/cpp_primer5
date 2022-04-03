#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <list>
#include <type_traits>
#include <cstring>

template <typename T, typename ...Args>
std::shared_ptr<T> my_make_shared(Args &&...args)
{
    return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
}

int main()
{
    auto ps = my_make_shared<std::string>(10, 'c');
    std::cout << *ps << std::endl;
    return 0;
}

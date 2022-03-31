#include <iostream>
#include <memory>
#include <vector>
#include <list>

template <typename T>
void print_container(const T &c)
{
    for (typename T::const_iterator beg = c.cbegin(); beg != c.cend(); ++beg) {
        std::cout << *beg << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> ivec{1, 2, 3};
    print_container(ivec);
    return 0;
}

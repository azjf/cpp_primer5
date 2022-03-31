#include <iostream>
#include <memory>
#include <vector>
#include <list>

template <typename T>
void print_container(const T &c)
{
    typename T::const_iterator beg = c.cbegin();
    for (typename T::size_type i = 0; i != c.size(); ++i) {
        std::cout << *(beg + i) << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> ivec{1, 2, 3};
    print_container(ivec);
    return 0;
}

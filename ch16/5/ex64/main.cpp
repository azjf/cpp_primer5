#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <list>
#include <unordered_set>
#include <type_traits>
#include <cstring>

template <typename T> std::size_t count(const std::vector<T> &, T);
template <> std::size_t count(const std::vector<const char *> &, const char *);

template <typename T>
std::size_t count(const std::vector<T> &vec, T target)
{
    std::size_t ret = 0;
    for (const auto &item : vec) {
        ret += item == target;
    }
    return ret;
}

template <>
std::size_t count(const std::vector<const char *> &vec, const char * target)
{
    std::size_t ret = 0;
    for (const auto &item : vec) {
        ret += std::strcmp(item, target) == 0;
    }
    return ret;
}

int main()
{
    std::cout << count(std::vector<int>{1, 1, 2, 3}, 1) << std::endl;

    //const int *pi = new int[3]{1, 2, 3};
    //const char *ps = new char[3]{"hi"};
    //std::vector<const char *> cpvec{new char[6]{"hello"}, new char[6]{"hello"},
    //    new char[6]{"world"}};
    std::vector<const char *> cpvec{std::string("hello").c_str(),
        std::string("hello").c_str(), std::string("world").c_str()};
    std::cout << count(cpvec, "hello") << std::endl;
    return 0;
}

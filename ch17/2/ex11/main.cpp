#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <numeric>

template <std::size_t N> class Quiz;
template <std::size_t N>
std::ostream &operator<<(std::ostream &, const Quiz<N> &);

template <std::size_t N>
class Quiz
{
    friend std::ostream &operator<<<N>(std::ostream &, const Quiz<N> &);

public:
    Quiz(const std::string &s) : bs(s) {}

private:
    std::bitset<N> bs;
};

template <std::size_t N>
std::ostream &operator<<(std::ostream &os, const Quiz<N> &quiz)
{
    std::cout << quiz.bs;
    return os;
}

int main()
{
    Quiz<10> quiz1("1010110101");
    std::cout << quiz1 << std::endl;

    Quiz<100> quiz2("1010110101");
    std::cout << quiz2<< std::endl;
    return 0;
}

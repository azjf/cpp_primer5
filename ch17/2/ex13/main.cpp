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

    std::size_t grade(const Quiz &answer) const;

private:
    std::bitset<N> bs;
};

template <std::size_t N>
std::ostream &operator<<(std::ostream &os, const Quiz<N> &quiz)
{
    std::cout << quiz.bs;
    return os;
}

template <std::size_t N>
std::size_t Quiz<N>::grade(const Quiz<N> &answer) const
{
    return (~(bs ^ answer.bs)).count();
}

int main()
{
    Quiz<10> quiz("1010110101");
    std::cout << quiz << std::endl;
    std::cout << quiz.grade(Quiz<10>("111")) << std::endl;
    return 0;
}

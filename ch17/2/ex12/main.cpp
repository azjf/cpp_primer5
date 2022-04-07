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

    void set(std::size_t i, bool value) { bs.set(i, value); }

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
    Quiz<10> quiz("1010110101");
    std::cout << quiz << std::endl;
    quiz.set(0, 0);
    std::cout << quiz << std::endl;
    return 0;
}

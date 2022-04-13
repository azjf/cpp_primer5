#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include <numeric>

void exercise(int *b, int *e)
{
    std::vector<int> v(b, e);
    int *p = new int[v.size()];
    std::ifstream in("ints");

    try {
        throw std::exception();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        delete []p;
    }
}

void exercise2(int *b, int *e)
{
    std::vector<int> v(b, e);
    std::unique_ptr<int[]> p(new int[v.size()]);
    std::ifstream in("ints");
    throw std::exception();
}

int main()
{
    int iarr[3]{0};
    exercise(std::begin(iarr), std::end(iarr));

    try {
        exercise2(std::begin(iarr), std::end(iarr));
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
